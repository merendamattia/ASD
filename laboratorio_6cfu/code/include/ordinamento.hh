#ifndef ORDINAMENTO_H
#define ORDINAMENTO_H

#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>

struct Stat {
	int ct_swap;
	int ct_cmp;
	int ct_read;
	int ct_op;

	int n; // dimensione dell'array
	int max_dim;
	int ntests;
	int ndiv;
	bool details;
	bool graph;
	bool comparison;

	// file di output per grafo
	std::string output_path;
	std::ofstream output_graph;

	Stat() :
		ct_swap(0),
		ct_cmp(0),
		ct_read(0),
		ct_op(0),
		n(0),
		max_dim(0),
		ntests(1),
		ndiv(1),
		details(false),
		graph(false),
		comparison(false),
		output_path("graph.dot"),
		output_graph() {
		}
};

struct my_pair {
    int x, y;
};

void print_usage(char **argv);
int parse_cmd(int argc, char **argv, Stat& s);
void print_array(int *A, int dim);
void swap(int &a, int &b, int& count);

#endif // ORDINAMENTO_H