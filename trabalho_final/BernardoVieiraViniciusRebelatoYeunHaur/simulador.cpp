// Simulador para uma Arquitetura Hipotética de Zero Operandos

// Arquiteura e Organização de Computadores - 2022/2
// Bernardo Vivian Vieira (179835), Vinicius Bernardi Rebelato (109547), Yeun-Haur Kang (193593)

#include <iostream> // cout, cin
#include <stack> // stack
#include <sstream> // stringstream
#include <vector> // vector

// Struct para a memória - 256 posições
struct memory {
    float values[256];
    std::vector<int> address;
};

// Struct para a máquina virtual - memória, erro e pilha
struct virtual_machine {
    memory mem;
    bool error;
    std::stack<float> stack;
};

// Função para transformar uma string em maiúsculas - retorna a string
std::string uppercase(std::string &str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
    return str;
}

// Função para identificar a operação - retorna o número da operação
int identify_operation(std::string operation) {
    const int op = 14;
    int count = 0;
    std::string operations[op] = {"PUSHI", "PUSH", "POP", "INPUT", "PRINT", "ADD", "SUB", "MUL", "DIV", "SWAP", "DROP", "DUP", "HLT", "ERROR"};
    while (count < op) {
        if (operations[count] == operation) {
            return count;
        }
        count++;
    }
    return 13;
}

// Função para executar a operação PUSHI - empilha um valor na pilha da máquina virtual
void pushi(virtual_machine &pc) {
    if (pc.stack.size() <= 16) {
        float value;
        std::cin >> value;
        pc.stack.push(value);
    } else {
        std::cout << "Stack Overflow\n";
        pc.error = true;
    }
}

// Função para executar a operação PUSH
void push(virtual_machine &pc) {
    int address;
    float value;
    std::cin >> std::hex >> address; // lê o endereço em hexadecimal
    if (address >= 0 && address <= 255) {
        value = pc.mem.values[address - 1];
        pc.stack.push(value);
    } else {
        std::cout << "Invalid Address\n";
        pc.error = true;
    }
}

// Função para executar a operação POP - desempilha um valor da pilha da máquina virtual
void pop(virtual_machine &pc) {
    int address;
    std::cin >> std::hex >> address; // lê o endereço em hexadecimal
    if (address >= 0 && address <= 255) {
        if (!pc.stack.empty()) {
            pc.mem.values[address - 1] = pc.stack.top();
            if (pc.mem.address.empty()) {
                pc.mem.address.push_back(address - 1);
                for (int i = 0; i < pc.mem.address.size(); i++) {
                    if (pc.mem.address[i] != address - 1) {
                        pc.mem.address.push_back(address - 1);
                    }
                }
            }
            pc.stack.pop();
        } else {
            std::cout << "Stack Underflow\n";
            pc.error = true;
        }
    } else {
        std::cout << "Invalid Address\n";
        pc.error = true;
    }
}

// Função para executar a operação INPUT - lê um valor do teclado e armazena em um endereço de memória
void input(virtual_machine &pc) {
    if (pc.stack.size() <= 16) {
        float value;
        std::cin >> value;
        pc.stack.push(value);
    } else {
        std::cout << "Stack Overflow\n";
        pc.error = true;
    }
}

// Função para executar a operação PRINT - imprime um valor da pilha da máquina virtual
void print(virtual_machine &pc) {
    if (pc.stack.size() > 0) {
        std::cout << pc.stack.top() << "\n";
        pc.stack.pop();
    } else {
        std::cout << "Stack Underflow\n";
        pc.error = true;
    }
}

// Função para executar a operação ADD - soma os dois valores do topo da pilha da máquina virtual
void add(virtual_machine &pc) {
    if (pc.stack.size() > 1) {
        float value1 = pc.stack.top();
        pc.stack.pop();
        float value2 = pc.stack.top();
        pc.stack.pop();
        pc.stack.push(value1 + value2);
    } else {
        std::cout << "Stack Underflow\n";
        pc.error = true;
    }
}

// Função para executar a operação SUB - subtrai os dois valores do topo da pilha da máquina virtual
void sub(virtual_machine &pc) {
    if (pc.stack.size() > 1) {
        float value1 = pc.stack.top();
        pc.stack.pop();
        float value2 = pc.stack.top();
        pc.stack.pop();
        pc.stack.push(value1 - value2);
    } else {
        std::cout << "Stack Underflow\n";
        pc.error = true;
    }
}

// Função para executar a operação MUL - multiplica os dois valores do topo da pilha da máquina virtual
void mul(virtual_machine &pc) {
    if (pc.stack.size() > 1) {
        float value1 = pc.stack.top();
        pc.stack.pop();
        float value2 = pc.stack.top();
        pc.stack.pop();
        pc.stack.push(value1 * value2);
    } else {
        std::cout << "Stack Underflow\n";
        pc.error = true;
    }
}

// Função para executar a operação DIV - divide os dois valores do topo da pilha da máquina virtual
void div(virtual_machine &pc) {
    if (pc.stack.size() > 1) {
        if (pc.stack.top() != 0) {
            float value1 = pc.stack.top();
            pc.stack.pop();
            float value2 = pc.stack.top();
            pc.stack.pop();
            pc.stack.push(value1 / value2);
        } else {
            std::cout << "Zero division error\n";
            pc.error = true;
        }
    } else {
        std::cout << "Stack Underflow\n";
        pc.error = true;
    }
}

// Função para executar a operação SWAP - troca os dois valores do topo da pilha da máquina virtual
void swap(virtual_machine &pc) {
    if (pc.stack.size() > 1) {
        float value1 = pc.stack.top();
        pc.stack.pop();
        float value2 = pc.stack.top();
        pc.stack.pop();
        pc.stack.push(value1);
        pc.stack.push(value2);
    } else {
        std::cout << "Stack Underflow\n";
        pc.error = true;
    }
}

// Função para executar a operação DROP - desempilha um valor da pilha da máquina virtual
void drop(virtual_machine &pc) {
    if (pc.stack.size() > 0) {
        pc.stack.pop();
    } else {
        std::cout << "Stack Underflow\n";
        pc.error = true;
    }
}

// Função para executar a operação DUP - duplica o valor do topo da pilha da máquina virtual
void dup(virtual_machine &pc) {
    if (pc.stack.size() > 0) {
        float value = pc.stack.top();
        pc.stack.push(value);
    } else {
        std::cout << "Stack Underflow\n";
        pc.error = true;
    }
}

// Função para identificar e executar a operação de acordo com o código lido
std::string execute_operation(std::string &operation, virtual_machine &pc) {
    uppercase(operation);
    switch (identify_operation(operation)) {
        case 0:
            pushi(pc);
            break;
        case 1:
            push(pc);
            break;
        case 2:
            pop(pc);
            break;
        case 3:
            input(pc);
            break;
        case 4:
            print(pc);
            break;
        case 5:
            add(pc);
            break;
        case 6:
            sub(pc);
            break;
        case 7:
            mul(pc);
            break;
        case 8:
            div(pc);
            break;
        case 9:
            swap(pc);
            break;
        case 10:
            drop(pc);
            break;
        case 11:
            dup(pc);
            break;
        case 12:
            operation = "HLT";
            break;
        case 13:
            operation = "ERROR";
            pc.error = true;
            break;
    }
    return operation;
}

// Função para encerrar a o programa
void end_program(virtual_machine &pc) {
    if (pc.error) {
        std::cout << "Programa encerrado com erro!\n";
    } else {
        std::cout << "Programa encerrado com sucesso!\n";
        if (pc.stack.empty()) {
            std::cout << "A pilha está vazia!\n";
        } else {
            std::cout << "Há valores na pilha:\n";
            while (!pc.stack.empty()) {
                std::cout << pc.stack.top() << "\n";
                pc.stack.pop();
            }
        }
        if (pc.mem.address.empty()) {
            std::cout << "A memória está vazia!\n";
        } else {
            std::cout << "Há valores na memória:\n";
            int i = 0;
            while (i < pc.mem.address.size()) {
                std::stringstream aux;
                aux << std::hex << pc.mem.address[i] + 1; // converte o endereço para hexadecimal
                std::string address = aux.str();
                int j = 0;
                while (address[j] != '\0') {
                    address[j] = toupper(address[j]); // converte o endereço para maiúsculo
                    j++;
                }
                std::cout << "Endereço " << address << ": " << pc.mem.values[(pc.mem.address[i])] << "\n";
                i++;
            }
        }
    }
}

int main() {
    // Criação da máquina virtual
    virtual_machine pc;

    // Define a variável de erro como false
    pc.error = false;

    // Variável para armazenar o código da operação	
    std::string operation;

    // Execução do programa
    while (operation != "HLT" && !pc.error) {
        std::cin >> operation;
        operation = execute_operation(operation, pc);
    }

    // Encerramento do programa
    end_program(pc);

    return 0;
}