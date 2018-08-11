#include<stdio.h>
#include<stdlib.h>

#define FALSE_SUDOKU   0
#define TRUE_SUDOKU    1

char sudoku[9][9] = {
    {0, 0, 5, 3, 0, 0, 0, 0, 0}, 
    {8, 0, 0, 0, 0, 0, 0, 2, 0}, 
    {0, 7, 0, 0, 1, 0, 5, 0, 0}, 
    {4, 0, 0, 0, 0, 5, 3, 0, 0}, 
    {0, 1, 0, 0, 7, 0, 0, 0, 6}, 
    {0, 0, 3, 2, 0, 0, 0, 8, 0}, 
    {0, 6, 0, 5, 0, 0, 0, 0, 9}, 
    {0, 0, 4, 0, 0, 0, 0, 3, 0}, 
    {0, 0, 0, 0, 0, 9, 7, 0, 0}, 
};

//检查九宫格中的index位置能否添val这个数，能填返回1，不能返回0
int CheckCell(char matrix[9][9],char index,char val)
{
    //确定Index处于九宫格中的哪一行、哪一列
    char row = index / 9;
    char col = index % 9;

    //确定每一行能否填val 这个数字
    for(char i=0;i<9;i++)
    {
        if( matrix[row][i] == val )
            return FALSE_SUDOKU;
    }
    //确定每一列能否填val 这个数字
    for(char i=0;i<9;i++)
    {
        if(matrix[i][col] == val)
            return FALSE_SUDOKU;
    }
    //确定每一个小格子能否填val这个数字
    //确定当前的index位于哪个小格子
    char rowIndexBox = row / 3 * 3;
    char colIndexBox = col / 3 * 3;

    for(char i=rowIndexBox;i<rowIndexBox+3;i++)
    {
        for(char j = colIndexBox;j<colIndexBox+3;j++)
        { 
            if(matrix[i][j] == val)
                return FALSE_SUDOKU;
        }
    }
    return TRUE_SUDOKU;
}

//判断一个数独是否填写正确
int CheckSudoku(char matrix[9][9])
{
    //检查每一行都等于45
    for(int i = 0;i<9;i++)
    {
        //累加每一列
        int sum =0;
        for(int j =0;j<9;j++)
        {
            sum += matrix[i][j];            
        }
        if(sum != 45)
            return FALSE_SUDOKU;
    }

    //检查每一列都等于45
    for(int j = 0;j<9;j++)
    {
        //累加每一列
        int sum =0;
        for(int i =0;i<9;i++)
        {
            sum += matrix[i][j];            
        }
        if(sum != 45)
            return FALSE_SUDOKU;
    }

    //检查每一个小格子都等于45
    char boxcenterindex[9] = {10,13,16,37,40,43,64,67,70};
    for(int m = 0;m<9;m++)
    {
        int row = boxcenterindex[m] / 9;
        int col = boxcenterindex[m] % 9;

        int boxStartRow = row / 3 * 3;
        int boxStartCol = col / 3 * 3;
        
        int sum = 0;
        for(int i = boxStartRow;i<boxStartRow + 3;i++)
        {
            for(int j = boxStartCol;j<boxStartCol + 3;j++)
            {
                sum += matrix[i][j];
            }
        }
        if(sum != 45)
            return FALSE_SUDOKU;
        sum = 0;
    }
    return TRUE_SUDOKU;
}

void PrintSudoku(char matrix[9][9])
{
    for(char i=0;i<9;i++)
    {
        for(char j=0;j<9;j++)
        {
            printf("%d  ",matrix[i][j]);        
        }    
        printf("\n");
    }
}

//递归回溯法求解数独
//按照格子顺序逐一填数，不成功则后退
void SolveSudoku(char matrix[9][9],int index )
{
    static int flag = 0;
    //如果能填完了80这个格子，则求解完成
    if(index > 80)
    {
        flag = 1;
        return ;
    }
    //没有填完整个数独就逐一填写格
    char row = index / 9;
    char col = index % 9;
    //判断当前各自有没有数字
    if( matrix[row][col] != 0)  //当前格子有数字，填写下一个格子
    {
        SolveSudoku(matrix,index+1);
    }
    //当前格子没有数字，能填啥就填啥
    else
    {
        //测试一下当前格子能填什么数字
        for(int i = 1;i<=9;i++)
        {
            //如果当前格子能填 i 这个数，则填数，继续填下一个格子
            if(CheckCell(matrix,index,i) == TRUE_SUDOKU)
            {
                matrix[row][col] = i;
                SolveSudoku(matrix,index+1);
                //如果函数一直没有返回，则填到了第80个格子
                if(flag == 1) return ;
                matrix[row][col] = 0;
            }
        }
    }
}


int main(void)
{
    printf("这是一个使用递归回溯法求解数独的例程\n");

    PrintSudoku(sudoku);
    int flag =  CheckSudoku(sudoku);
    printf("检查数独:正确 -- 1 ? 错误 -- 0  ?? %d\n",flag);
    
    SolveSudoku(sudoku,0);
    printf("求解数独\n");
    PrintSudoku(sudoku);

    flag =  CheckSudoku(sudoku);
    printf("检查数独:正确 -- 1 ? 错误 -- 0  ?? %d\n",flag);
    return 0;
}
