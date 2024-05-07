function writeDataToTable(data) {
    const tableBody = document.getElementById('data_table_body');

    // Créer une nouvelle ligne dans le tableau pour chaque valeur
    const row = document.createElement('tr');
    for (const key in data) {
        const value = data[key];
        const cell = document.createElement('td');
        cell.textContent = value;
        row.appendChild(cell);
    }

    // Ajouter la nouvelle ligne au tableau
    tableBody.appendChild(row);
}


// Sélectionner le formulaire
const form = document.getElementById('studentForm');

// Ajouter un écouteur d'événement pour le soumission du formulaire
form.addEventListener('submit', function(event) {
    // Empêcher le comportement par défaut du formulaire (rechargement de la page)
    event.preventDefault();

    // Récupérer tous les champs de saisie avec l'attribut de données "data-input"
    const inputs = form.querySelectorAll('[data-input]');

    // Créer un objet pour stocker les valeurs des champs
    const base_donnees = {};

    // Boucler à travers les champs de saisie et récupérer leurs valeurs
    inputs.forEach(input => {
        const key = input.dataset.input; // Récupérer la clé à partir de l'attribut de données
        const value = input.value; // Récupérer la valeur du champ de saisie
        base_donnees[key] = value; // Ajouter la clé et la valeur à l'objet base_donnees
    });

    // Utiliser les valeurs récupérées (vous pouvez les afficher, les enregistrer dans un objet, les envoyer à un serveur, etc.)
    console.log(base_donnees);
    writeDataToTable(base_donnees);
});

