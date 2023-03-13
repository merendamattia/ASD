#include "../include/ordinamento.hh"

void print_usage(char **argv) {
	using std::cerr;

    cerr << "Usage: " << argv[0] << " max-dim [Options]\n";
        cerr << "   max-dim: specifica la massima dimensione n del problema\n";
        cerr << "Options:\n";
        cerr << "  -d=<int>: Specifica quali dimensioni n del problema vengono lanciate in sequenza [default: 1] \n";
        cerr << "            n = k * max-dim / d, k=1 .. d\n";
        cerr << "  -t=<int>: Specifica quanti volte viene lanciato l'algoritmo per una specifica dimensione n [default: 1]\n";
        cerr << "            Utile nel caso in cui l'input viene inizializzato in modo random\n";
        cerr << "  -v, --verbose: Abilita stampe durante l'esecuzione dell'algoritmo\n";
        cerr << "  -g, --graph: creazione file di dot con il grafo dell'esecuzione (forza d=1 t=1)\n";
        cerr << "  -c, --comparison: (quicksort) compara la partition a tre vie classica con un'altra\n";
        cerr << "  -o, --output-file: specifica un path per il file di dot\n";
}


int parse_cmd(int argc, char **argv, Stat& s) {
    if (argc < 2) {
        print_usage(argv);
        return 1;
    }

    int option_index = 0;
    static struct option long_options[] = {
        {"graph"        , no_argument       , 0,    'g'},
        {"verbose"      , no_argument       , 0,    'v'},
        {"comparison"   , no_argument       , 0,    'c'},
        {"output-file"  , required_argument , 0,    'o'}
    };

    int c;
    while ((c = getopt_long(argc, argv, ":d:t:o:vgc", long_options, &option_index)) != -1) {
        switch (c) {
        case 'v':
            s.details = true;
            break;
        case 'c':
            s.comparison = true;
            break;
        case 'g':
            s.graph = 1;
            s.ndiv = 1;
            s.ntests = 1;
            break;
        case 'd':
            s.ndiv = atoi(optarg);
            break;
        case 't':
            s.ntests = atoi(optarg);
            break;
        case 'o':
            s.output_path = std::string(optarg);
            break;
        case ':':
            std::cerr << "Option -" << (char)optopt << " needs an argument." << std::endl;
            print_usage(argv);
            return 1;
        case '?':
            std::cerr << "Unknown option -" << (char)optopt << std::endl;
            print_usage(argv);
            return 1;
        default:
            break;
        }
    }

    /* 
    while ((c = getopt(argc, argv, ":d:t:o:vgc")) != -1) {
        switch (c) {
        case 'v':
            s.details = true;
            break;
        case 'c':
            s.comparison = true;
            break;
        case 'g':
            s.graph = 1;
            s.ndiv = 1;
            s.ntests = 1;
            break;
        case 'd':
            s.ndiv = atoi(optarg);
            break;
        case 't':
            s.ntests = atoi(optarg);
            break;
        case 'o':
            s.output_path = std::string(optarg);
            break;
        case ':':
            std::cerr << "Option -" << (char)optopt << " needs an argument." << std::endl;
            print_usage(argv);
            return 1;
        case '?':
            std::cerr << "Unknown option -" << (char)optopt << std::endl;
            print_usage(argv);
            return 1;
        default:
            break;
        }
    }

	s.max_dim = atoi(argv[optind]); 
    */
    if (optind == argc-1) {
	    s.max_dim = atoi(argv[optind++]); 
    } else
        print_usage(argv);

    if (s.ndiv > s.max_dim) {
        std::cerr << "-d argument must be less or equal to max-dim" << std::endl;
        return 1;
    }
	
	return 0;
}

void print_array(int *A, int dim) {
    for (int j = 0; j < dim; j++) {
        std::cout << A[j] << ' ';
    }
    std::cout << std::endl;
}

void swap(int &a, int &b, int& count) {
    int tmp = a;
    a = b;
    b = tmp;
    /// aggiorno contatore globale di swap
    ++count;
}