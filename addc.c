#include <stdio.h>
#include <math.h>
#define NUM 20


// 平均値を計算する関数
double ave(int arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// 標準偏差を計算する関数
double st_dev(int arr[], int size, double mean) {
    double sum_squared_diff = 0;
    for (int i = 0; i < size; i++) {
        double diff = arr[i] - mean;
        sum_squared_diff += diff * diff;
    }
    return sqrt(sum_squared_diff / size);
}

// 偏差値を計算する関数
void dev(int arr[], int size, double mean, double stdev, double deviation_scores[]) {
    for (int i = 0; i < size; i++) {
        deviation_scores[i] = ((double)arr[i] - mean) / stdev * 10 + 50;
    }
}

// 配列を降順にソートする関数
void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                // 交換
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main() {
    // 理科の点数
    int sci_score[] = { 65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70 };
    int sci_size = NUM;

    // 英語の点数
    int eng_score[] = { 44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84 };
    int eng_size = NUM;

    // 理科の平均点、標準偏差、合計点の計算
    double sci_mean = ave(sci_score, sci_size);
    double sci_stdev = st_dev(sci_score, sci_size, sci_mean);
    int sci_sum = 0;
    for (int i = 0; i < sci_size; i++) {
        sci_sum += sci_score[i];
    }

    // 英語の平均点、標準偏差、合計点の計算
    double eng_mean = ave(eng_score, eng_size);
    double eng_stdev = st_dev(eng_score, eng_size, eng_mean);
    int eng_sum = 0;
    for (int i = 0; i < eng_size; i++) {
        eng_sum += eng_score[i];
    }

    // 各人の偏差値の計算
    double sci_deviation_scores[NUM];
    dev(sci_score, sci_size, sci_mean, sci_stdev, sci_deviation_scores);

    double eng_deviation_scores[NUM];
    dev(eng_score, eng_size, eng_mean, eng_stdev, eng_deviation_scores);

    // 点数の高い順に並べ替え
    sort(sci_score, sci_size);
    sort(eng_score, eng_size);

    // 結果の表示
    printf("理科の平均点: %.2f\n", sci_mean);
    printf("理科の標準偏差: %.2f\n", sci_stdev);
    printf("理科の合計点: %d\n", sci_sum);
    printf("\n");
    printf("理科の点数の高い順:\n");
    for (int i = 0; i < sci_size; i++) {
        printf("%d ", sci_score[i]);
    }
    printf("\n");
    printf("\n");
    printf("理科の偏差値:\n");
    for (int i = 0; i < sci_size; i++) {
        printf("学生%d: %.2f\n", i + 1, sci_deviation_scores[i]);
    }
    printf("\n");
    printf("\n");

    printf("英語の平均点: %.2f\n", eng_mean);
    printf("英語の標準偏差: %.2f\n", eng_stdev);
    printf("英語の合計点: %d\n", eng_sum);
    printf("\n");
    printf("英語の点数の高い順:\n");
    for (int i = 0; i < eng_size; i++) {
        printf("%d ", eng_score[i]);
    }
    printf("\n");
    printf("\n");
    printf("英語の偏差値:\n");
    for (int i = 0; i < eng_size; i++) {
        printf("学生%d: %.2f\n", i + 1, eng_deviation_scores[i]);
    }


    printf("\n");

    return 0;
}
