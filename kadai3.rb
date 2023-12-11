def average(scores)
  sum = scores.sum
  sum.to_f / scores.length
end

def standard_deviation(scores, mean)
  sum_squared_diff = scores.reduce(0) { |acc, score| acc + (score - mean)**2 }
  Math.sqrt(sum_squared_diff / scores.length)
end

def deviation(scores, mean, std_dev)
  scores.map { |score| 10 * (score - mean) / std_dev + 50 }
end

def sum(scores)
  scores.sum
end

#def sort(scores)
#  scores.sort { |a, b| b <=> a }
#end

science_scores = [65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70]
english_scores = [44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84]

science_ave = average(science_scores)
english_ave = average(english_scores)

science_std = standard_deviation(science_scores, science_ave)
english_std = standard_deviation(english_scores, english_ave)

science_dev = deviation(science_scores, science_ave, science_std)
english_dev = deviation(english_scores, english_ave, english_std)

science_sum = sum(science_scores)
english_sum = sum(english_scores)

sorted_science_scores = sort(science_scores)
sorted_english_scores = sort(english_scores)

puts "理科の平均点: #{science_ave.round(2)}"
puts "理科の標準偏差: #{science_std.round(2)}"
puts "理科の合計点: #{science_sum.round(2)}"
puts "理科の偏差値: #{science_dev.map { |dev| dev.round(2) }.join(' ')}"
puts "理科の点数(sort）: #{sorted_science_scores.join(' ')}\n"

puts "英語の平均点: #{english_ave.round(2)}"
puts "英語の標準偏差: #{english_std.round(2)}"
puts "英語の合計点: #{english_sum.round(2)}"
puts "英語の偏差値: #{english_dev.map { |dev| dev.round(2) }.join(' ')}"
puts "英語の点数(sort）: #{sorted_english_scores.join(' ')}"
