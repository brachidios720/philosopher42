## philosopher42 — `README.md`

```md
# philosopher42

Implémentation du problème des philosophes en C avec threads et synchronisation.

## À propos

Ce projet explore la programmation concurrente à travers le célèbre problème des dining philosophers.

## Notions travaillées

- threads
- mutex
- synchronisation
- race conditions
- deadlocks
- gestion du temps

## Objectif

Construire une simulation fiable, sans data races, avec une gestion propre des ressources partagées.

## Compilation

```bash
make
Exécution
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
