#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

// 関数宣言
double calculate_mean(const std::vector<int>& scores);
double calculate_std_dev(const std::vector<int>& scores, double mean);
void calculate_z_scores(const std::vector<int>& scores, double mean, double std_dev, std::vector<double>& z_scores);
void display_results(const std::vector<int>& scores, const std::vector<double>& z_scores);

int main() {
    // テストの点数データ
    std::vector<int> science_scores = { 65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70 };
    std::vector<int> english_scores = { 44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84 };

    // 理科の平均点、標準偏差、合計点の計算
    double science_mean = calculate_mean(science_scores);
    double science_std_dev = calculate_std_dev(science_scores, science_mean);
    double science_total = std::accumulate(science_scores.begin(), science_scores.end(), 0);

    // 英語の平均点、標準偏差、合計点の計算
    double english_mean = calculate_mean(english_scores);
    double english_std_dev = calculate_std_dev(english_scores, english_mean);
    double english_total = std::accumulate(english_scores.begin(), english_scores.end(), 0);

    // 理科と英語の偏差値の計算
    std::vector<double> science_z_scores, english_z_scores;
    calculate_z_scores(science_scores, science_mean, science_std_dev, science_z_scores);
    calculate_z_scores(english_scores, english_mean, english_std_dev, english_z_scores);

    // 結果の表示
    std::cout << "理科の平均点: " << science_mean << std::endl;
    std::cout << "理科の標準偏差: " << science_std_dev << std::endl;
    std::cout << "理科の合計点: " << science_total << std::endl;
    std::cout << "英語の平均点: " << english_mean << std::endl;
    std::cout << "英語の標準偏差: " << english_std_dev << std::endl;
    std::cout << "英語の合計点: " << english_total << std::endl;

    // 偏差値と点数の高い順に表示
    std::cout << "\n理科の偏差値と点数（高い順）:\n";
    display_results(science_scores, science_z_scores);

    std::cout << "\n英語の偏差値と点数（高い順）:\n";
    display_results(english_scores, english_z_scores);

    return 0;
}

// 平均の計算
double calculate_mean(const std::vector<int>& scores) {
    return static_cast<double>(std::accumulate(scores.begin(), scores.end(), 0)) / scores.size();
}

// 標準偏差の計算
double calculate_std_dev(const std::vector<int>& scores, double mean) {
    double variance = 0.0;
    for (int score : scores) {
        variance += std::pow(score - mean, 2);
    }
    return std::sqrt(variance / scores.size());
}

// 偏差値の計算
void calculate_z_scores(const std::vector<int>& scores, double mean, double std_dev, std::vector<double>& z_scores) {
    z_scores.resize(scores.size());
    for (size_t i = 0; i < scores.size(); ++i) {
        z_scores[i] = 50.0 + 10.0 * (scores[i] - mean) / std_dev; // 修正された偏差値の計算式
    }
}

// 結果の表示
void display_results(const std::vector<int>& scores, const std::vector<double>& z_scores) {
    std::vector<std::pair<int, double>> combined_scores;
    for (size_t i = 0; i < scores.size(); ++i) {
        combined_scores.push_back(std::make_pair(scores[i], z_scores[i]));
    }

    // 点数の高い順に並べ替え
    std::sort(combined_scores.begin(), combined_scores.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.first > rhs.first;
        });

    // 結果の表示
    for (const auto& pair : combined_scores) {
        std::cout << "点数: " << pair.first << "  偏差値: " << pair.second << std::endl;
    }
}
