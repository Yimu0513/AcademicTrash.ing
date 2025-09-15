#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// 定义表格A、B、C（5x5）
int A[SIZE][SIZE] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
};

int B[SIZE][SIZE] = {
    {1, 3,  6,  11, 16},
    {2, 5,  10, 15, 17},
    {4, 9,  14, 16, 20},
    {7, 13, 15, 19, 23},
    {12,14, 18, 21, 25}
};

int C[SIZE][SIZE] = {
    {1, 3, 5, 7, 9},
    {2, 4, 6, 8, 10},
    {11, 13, 15, 17, 19},
    {12, 14, 16, 18, 20},
    {21, 22, 23, 24, 25}
};

// 定义表格a、b、c（2x5）
int a[2][SIZE] = {
    {1, 2, 3, 4, 5},
    {2, 8, 14, 20, 25}
};

int b[2][SIZE] = {
    {1, 2, 3, 4, 5},
    {5, 10, 15, 20, 25}
};

int c[2][SIZE] = {
    {1, 2, 3, 4, 5},
    {3, 11, 17, 22, 25}
};

// 查找一个值所属的区间
int find_interval(int value, int intervals[2][SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (value <= intervals[1][i]) {
            return intervals[0][i];
        }
    }
    return -1; // 如果找不到，返回 -1，表示异常
}

int main() {
    FILE *input_file = fopen("data.csv", "r");
    if (input_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // 读取CSV的头行
    char header[100];
    fgets(header, sizeof(header), input_file); // 跳过表头


    // 打开输出CSV文件
    FILE *output_file = fopen("output.csv", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // 写入CSV文件的表头
    fprintf(output_file, "A1,B1,C1,Z1,ZD1\n");

    int A1, B1, C1;
    while (fscanf(input_file, "%d,%d,%d\n", &A1, &B1, &C1) != EOF) {
        // Step 1
        printf(" %d %d %d\n",A1, B1, C1);
        int AC1 = A[A1-1][C1-1]; // A1和C1用作表A的行列索引
        int ACD1 = find_interval(AC1, a);
        printf("value1: %d",ACD1);

        // Step 2
        int BC1 = B[B1-1][C1-1]; // B1和C1用作表B的行列索引
        int BCD1 = find_interval(BC1, b);
        printf(" value2: %d",BCD1);

        // Step 3
        int Z1 = C[ACD1-1][BCD1-1]; // ABD1 和 BCD1 用作表C的行列索引
        int ZD1 = find_interval(Z1, c);
        printf(" value3: %d\n",ZD1);

        // Step 4
        printf("A1=%d, B1=%d, C1=%d, Z1=%d, ZD1=%d\n", A1, B1, C1, Z1, ZD1);

        // Step 4: 写入输出文件
        fprintf(output_file, "%d,%d,%d,%d,%d\n", A1, B1, C1, Z1, ZD1);
    }

    // 关闭文件
    fclose(input_file);
    fclose(output_file);

    printf("Output has been written to output.csv.\n");
    return 0;
}