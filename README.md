# Graphiz

## Overview

Analog is a command-line tool designed for analyzing log files and generating graphical representations of website traffic patterns. It provides insights into the frequency and relationships between different web pages based on log data. Analog supports various options to tailor the analysis and visualization process according to user preferences.

## Getting Started

### Installation

To use Analog, follow these steps:

1. Clone the repository: `git clone https://example.com`
2. Change to the Analog directory: `cd analog`
3. Compile the source code: `make`
4. The compiled code can be found in `/bin` folder

### Usage

Run Analog with the following command format:

```bash
$ ./analog [options] nomfichier.log
```

#### Flags

`-g [filename]`: This option produces a GraphViz format file of the analyzed graph. Each document appears as a node, and each arc indicates the number of associated visits.

```bash
$ ./analog -g [filename] nomfichier.log
```

`-e`: This option excludes all documents with image, CSS, or JavaScript file extensions.

```bash
$ ./analog -e nomfichier.log
```

`-t hour`: This option considers only hits within the time slot corresponding to the interval [heure, heure+1[.

```bash
$ ./analog -t [hour] nomfichier.log
```


### Tutorials

#### 1. Basic Execution

Run Analog without any options to display basic statistics:

```bash
$ ./analog court.log
/page2.html (3 hits)
/image.jpg (1 hits)
/page3.html (1 hits)
/page1.html (1 hits)
```

#### 2. Execution with options -e and -g

Run Analog with options -e and -g to generate dot files:

```bash
$ ./analog -e -g court.dot court.log
Dot-file court.dot generated
/page2.html (3 hits)
/page3.html (1 hits)
/page1.html (1 hits)
```

The generated court.dot file:

```
digraph {
  node1 [label="/page1.html"];
  node0 [label="/page2.html"];
  node2 [label="/page3.html"];
  node0 -> node1 [label="1"];
  node0 -> node2 [label="1"];
  node1 -> node0 [label="2"];
  node2 -> node0 [label="1"];
}
```

#### 3. Execution with options -t and -g

```bash
$ ./analog -e -g court.dot court.log
Dot-file court.dot generated
/page2.html (3 hits)
/page3.html (1 hits)
/page1.html (1 hits)

```
The generated court.dot file:

```
digraph {
  node1 [label="/page1.html"];
  node0 [label="/page2.html"];
  node2 [label="/page3.html"];
  node0 -> node1 [label="1"];
  node0 -> node2 [label="1"];
  node1 -> node0 [label="2"];
  node2 -> node0 [label="1"];
}


