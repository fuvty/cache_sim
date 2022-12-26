# project directory
project_dir="./"

# cache size (kB)
cache_size=8

# cacheline size (B)
cacheline_size=64

# cache placement policy (directive_mapped: 1; set_associative: 2; full_associative: 3)
placement_policy=2

# associativity (lines in each set)
associativity=8

# cache replacement policy (FIFO: 1; LRU: 2; LFU: 3; Random: 4)
replacement_policy=2

# cache write policy (write through: 1; write back: 2)
write_policy=1

# input trace folder
input_dir="./input"

# output trace folder
output_dir="./output"

# input trace file
input_file="example.trace"

# output trace file
output_file="example.trace"

# define the input/output files
input_trace=$input_dir/$input_file
output_trace=$output_dir/$output_file

# run the code
$project_dir/build/CacheSim $cache_size $cacheline_size $placement_policy $associativity $replacement_policy $write_policy $input_trace $output_trace