Compression and decompression programs for:
    .ppm pictures
    text files

# Usage
## Compressing
    ./sm_antman -c input_file -t type

## Decompressing
    ./sm_antman -d input_file -t type

type: 0 - text, 1 - picture

# Algorithm explanation
## Pictures
The algorithm is based on the Huffman algorithm. The program reads the file and counts the number of times each character appears. Then it creates a tree with the characters and their frequencies. These frequencies are written in the compressed file.
### Example
    Input: 
        255
        255
        255
        125
    Output:
        255(0-2)
        125(3)

## Text
The algorithm use the run-length encoding. The program reads the file and counts the number of times each character appears. Then it creates a tree with the characters and their frequencies. These frequencies are written in the compressed file.

Do not use text with numbers in it. The program will not work properly.

### Example
    Input: 
        aaaaabbbbbccccc
    Output:
       5a5b5c