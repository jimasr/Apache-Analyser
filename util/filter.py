import sys

def filter_log(input_file, output_file, expr=" /SiteWebIF/Intranet-etudiant.php"):
    with open(input_file, "r") as file:
        filtered_lines = [line.strip() for line in file if expr in line]

    with open(output_file, "w") as output_file:
        output_file.write("\n".join(filtered_lines))

if __name__ == "__main__":
    args = sys.argv

    if len(args) != 3:
        print("Usage: python filter.py input_log_file output_log_file ")
        exit(1)
    
    input_log_file = args[1]
    output_log_file = args[2]
    expr = input("Enter the expression to filter: ")
    filter_log(input_log_file, output_log_file, expr)