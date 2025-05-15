#include <stdio.h>
#include <string>

class AntonyGoty {
    public:
        std::string name;
        int year;
        int rating;
        int votes;
        int rank;

        // Corrigido o construtor com a lista de inicialização
        AntonyGoty(std::string n, int y, int r, int v, int rk, int c, std::string e) 
            : name(n), year(y), rating(r), votes(v), rank(rk), cpf(c), address(e) {}

        std::string getName() {
            return name;
        }

        std::string gc() {
            return std::to_string(getCpf());
        }

    private:
        int cpf;
        std::string address;

        int getCpf() {
            return cpf;
        }
};

int main() {
    AntonyGoty goty("Lebron", 2023, 9, 1000, 1, 123456789, "123 Main St");
    printf("Name: %s\n", goty.getName().c_str());
    printf("Year: %d\n", goty.year);
    printf("Rating: %d\n", goty.rating);
    printf("Votes: %d\n", goty.votes);
    printf("Rank: %d\n", goty.rank);
    printf("CPF: %s\n", goty.gc().c_str());
    return 0;
}