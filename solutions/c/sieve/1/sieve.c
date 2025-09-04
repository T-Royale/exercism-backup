#include "sieve.h"
#include <stdbool.h> // Para manejar valores booleanos

// returns number of calculated primes, truncated to max_primes if necessary
uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
    if (limit < 2) return 0;  // No hay primos menores que 2

    bool is_prime[limit + 1];  // Aumentamos el tamaño para incluir 'limit'
    uint32_t nPrimes = 0;

    // Inicializa todos los números como primos
    for (uint32_t i = 2; i <= limit; i++) {
        is_prime[i] = true;
    }

    // Tamizado: quitar los compuestos
    for (uint32_t i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            // Invalidar todos los múltiplos de i
            for (uint32_t j = i * i; j <= limit; j += i) {
                is_prime[j] = false;  // Marca como compuesto
            }
        }
    }

    // Recolectar los números primos
    for (uint32_t i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            if (nPrimes < max_primes) {  // Solo almacenar hasta max_primes
                primes[nPrimes] = i;
            }
            nPrimes++;
        }
    }

    return (nPrimes > max_primes) ? max_primes : nPrimes;  // Devuelve los primos calculados o truncados
}












