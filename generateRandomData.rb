

numbers = Array.new

10000.times {
	numbers.push(rand(1.0..1000.0).round(3))
}

numbers = numbers.sort.reverse

File.open("sampleDataSortedReverse.txt", "w+") do |f|
	numbers.each { |num| f.puts(num) }
end

