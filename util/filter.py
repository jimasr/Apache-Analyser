def filter_log(input_file, output_file):
    with open(input_file, "r") as file:
        filtered_lines = [line.strip() for line in file if " /SiteWebIF/Intranet-etudiant.php" in line]

    with open(output_file, "w") as output_file:
        output_file.write("\n".join(filtered_lines))

if __name__ == "__main__":
    input_log_file = "src/test.log"
    output_log_file = "filtered_log.txt"
    filter_log(input_log_file, output_log_file)