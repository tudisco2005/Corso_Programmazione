/*
Tempo: 30 min.
Si ricorda che, dato un angolo θ, la matrice
R(θ) := 
cos θ − sin θ
sin θ cos θ

è detta matrice di rotazione (di angolo θ). Dato un vettore ⃗v ∈ R
2
, il prodotto
R(θ)⃗v è l’immagine del vettore ⃗v dopo la rotazione in senso antiorario del piano di
un angolo θ attorno all’origine.
Scrivete una funzione di prototipo:
void rot(Vett *, double a)
che applichi al vettore passato come primo parametro la rotazione attorno all’origine
di un angolo a. (Suggerimento. Per calcolare seni e coseni, usate le funzioni double
sin(double) e double cos(double) definite nel file di intestazione math.h della
libreria standard.) Scrivete poi una funzione di prototipo:
void rot(Tri *, double a)
cha applichi la rotazione al triangolo passato come argomento.
Scrivete un programma che permetta all’utente di specificare un triangolo nel
piano tramite le coordinate dei suoi vertici, assieme a un angolo θ (espresso in
radianti e codificato come tipo double). Il programma calcola e visualizza l’area
del triangolo — si usi la funzione scritta per risolvere l’Esercizio 15 — applica al
triangolo la rotazione antioraria di angolo θ, calcola e visualizza nuovamente l’area
del triangolo dopo la rotazione, e termina.
*/