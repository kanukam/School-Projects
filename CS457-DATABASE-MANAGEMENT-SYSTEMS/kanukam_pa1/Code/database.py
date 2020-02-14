# Name: Kennedy Anukam
# Date: 1/30/20
# Class: CS 457
# Purpose: Creating a relational database management system
import datahelper
import sys
import platform


# Main Function to take in user input through standard input
def main():
    print("Kennedy Anukam's relational database management system,"
          " enter .EXIT to end program")
    # Check if being ran on a Linux system with standard input
    if not sys.stdin.isatty() and 'Linux' == platform.system():
        data = sys.stdin.read().splitlines()
        # Loop through standard input queries
        for i in data:
            # Exit condition
            if i.lower() == ".exit;" or i.lower() == ".exit":
                break
            else:
                datahelper.statement(i)
        print("All done.")
    else:
        # Continues until exit command entered
        while True:
            line = input()
            # Exit condition
            if line.lower() == ".exit;" or line.lower() == ".exit":
                break
            else:
                datahelper.statement(line)
        print("All done.")


if __name__ == '__main__':
    main()
