'''
    DIPHA Format file converter                             M. Tallon
                                                    (small edits by N. Carrara)

'''

import pandas as pd
import struct


def convert_csv_to_dipha(input_file, output_file):

    df = pd.read_csv(input_file, header=None)

    array_size = df.shape[1]
    iterations = df.shape[0]

    with open(output_file, 'wb') as f:
        symbol = struct.pack("<Q", 8067171840) # magic number
        f.write(symbol)
        symbol = struct.pack("<Q", 1) # 1 = Image file
        f.write(symbol)
        symbol = struct.pack("<Q", array_size * iterations) # image size
        f.write(symbol)
        symbol = struct.pack("<Q", 2) # 2 dimensions
        f.write(symbol)
        symbol = struct.pack("<Q", array_size) # image width
        f.write(symbol)
        symbol = struct.pack("<Q", iterations) # image height
        f.write(symbol)

        # add data for all points
        for row in range(df.shape[0]):
            for col in range(df.shape[1]):
                value = df.iloc[row, col]
                symbol = struct.pack("<d", value)
                f.write(symbol)
    print("Converted %s to DIPHA format file %s\n" % (input_file, output_file))


if __name__ == "__main__":
    INPUT_FILE = "/home/milo/MATH585/Automata/src/Rule_26.csv"
    OUTPUT_FILE = "/home/milo/MATH585/CubicalRipser_2dim/Rule_26.complex"
    convert_csv_to_dipha(INPUT_FILE, OUTPUT_FILE)