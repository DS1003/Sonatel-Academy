<?php

    include 'config.php';


    // Déclaration d'une variable de chaîne de caractères
    $nom = "Seydina Mouhammad Diop";

    // Déclaration d'une variable entière
    $age = 224;

    // Déclaration d'une variable à virgule flottante (nombre décimal)
    $salaire = 200000;

    // Déclaration d'une variable booléenne
    $isValid = true;

    // Déclaration d'une variable tableau
    $prenoms = array("Seydina", "Mouhammad");

    // Déclaration d'une variable null
    $somme = null;


// Utilisation des variables déclarées précédemment
echo "Nom : " . $nom . "<br>";
echo "Âge : " . $age . "<br>";
echo "Salaire : $" . $salaire . "<br>";
echo "Actif : " . ($isValid ? 'Oui' : 'Non') . "<br>";

// Parcourir et afficher les éléments d'un tableau
foreach ($prenoms as $prenom) {
    echo "Prénom : " . $prenom . "<br>";
}

// Utilisation de la variable null
if ($somme === null) {
    echo "La variable est nulle";
}



function additionner($a, $b) {
    return $a + $b;
}

function bonjour($nom = "Diop") {
    echo "Bonjour, $nom !";
}

$notes = array(10, 15, 18);

$personne = array("nom" => "Smith", "âge" => 30, "ville" => "Paris");

