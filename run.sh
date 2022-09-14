#! /bin/bash

# project directory
project_dir="/home/futy18/nfs/repos/prime/DATE23/CacheSim"

# cache size (kB)
cache_size=16

# cacheline size (B)
cacheline_size=4

# cache placement policy (directive_mapped: 1; set_associative: 2; full_associative: 3)
placement_policy=2

# associativity (lines in each set)
associativity=4

# cache replacement policy (FIFO: 1; LRU: 2; LFU: 3; Random: 4)
replacement_policy=2

# cache write policy (write through: 1; write back: 2)
write_policy=1

# input trace folder
input_dir="/home/futy18/nfs/repos/prime/DATE23/CacheSim/trace/input"

# output trace folder
output_dir="/home/futy18/nfs/repos/prime/DATE23/CacheSim/trace/output"

graph="test"
# for graph in {"p2p","astro","mico","youtube","lj","patent"}; do
# for graph in {"lj","youtube"}; do
# graph="mico"
    input_trace="$input_dir/${graph}.trace"
    # for cache_size in {4,8,16,32,64,128}; do
    # for cache_size in {16,64}; do
        output_trace="$output_dir/${graph}_${cache_size}.trace"
        std_out="$output_dir/${graph}_${cache_size}.stdout"
        # echo -e "${cache_size}  $cacheline_size  $placement_policy  $associativity  $replacement_policy $write_policy  $input_trace $output_trace e" | 
        $project_dir/build/CacheSim $cache_size $cacheline_size $placement_policy $associativity $replacement_policy $write_policy $input_trace $output_trace > $std_out
    # done
# done
