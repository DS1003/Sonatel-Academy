let profile = document.querySelector(".header .profile");

document.querySelector("#user-btn").onclick = () => {
  profile.classList.toggle("active");
  search.classList.remove("active");
};

let toggleBtn = document.getElementById("toggle-btn");
let body = document.body;
let darkMode = localStorage.getItem("dark-mode");

const enableDarkMode = () => {
  toggleBtn.classList.replace("fa-sun", "fa-moon");
  body.classList.add("dark");
  localStorage.setItem("dark-mode", "enabled");
};

const disableDarkMode = () => {
  toggleBtn.classList.replace("fa-moon", "fa-sun");
  body.classList.remove("dark");
  localStorage.setItem("dark-mode", "disabled");
};

if (darkMode === "enabled") {
  enableDarkMode();
}

toggleBtn.onclick = (e) => {
  darkMode = localStorage.getItem("dark-mode");
  if (darkMode === "disabled") {
    enableDarkMode();
  } else {
    disableDarkMode();
  }
};

const DB = {
  etudiants: [
    {
      id_etudiant: 1,
      image: "https://cdn-icons-png.flaticon.com/128/3135/3135715.png",
      prenom: "Seydina Mouhammad",
      nom: "Diop",
      telephone: "+221705813257",
      date_naissance: "1999-10-17",
      numero_carte_identite: "1752199901212",
      sexe: "M",
      lieuNaissance: "Dakar",
      referentiel: "dev_web",
      id_promo: 6,
    },
    {
      id_etudiant: 2,
      image: "https://cdn-icons-png.flaticon.com/128/6997/6997662.png",
      prenom: "Ndeye Amy",
      nom: "Sène",
      telephone: "+221771443400",
      date_naissance: "2004-04-23",
      numero_carte_identite: "1751200401717",
      sexe: "F",
      lieu_naissance: "Paris",
      referentiel: "dev_web",
      id_promo: 6,
    },
  ],
  promotions: [
    {
      id_promo: 1,
      nom: "Prolotion 1",
      dateDebut: "01/01/2022",
      dateFin: "01/01/2023",
      etat: false,
    },
    {
      id_promo: 2,
      nom: "Prolotion 2",
      dateDebut: "01/01/2022",
      dateFin: "01/01/2023",
      etat: false,
    },
    {
      id_promo: 3,
      nom: "Prolotion 3",
      dateDebut: "01/01/2022",
      dateFin: "01/01/2023",
      etat: false,
    },
    {
      id_promo: 4,
      nom: "Prolotion 4",
      dateDebut: "01/01/2022",
      dateFin: "01/01/2023",
      etat: false,
    },
    {
      id_promo: 5,
      nom: "Prolotion 5",
      dateDebut: "01/01/2022",
      dateFin: "01/01/2023",
      etat: false,
    },
    {
      id_promo: 6,
      nom: "Prolotion 6",
      dateDebut: "01/01/2022",
      dateFin: "01/01/2023",
      etat: true,
    },
  ],
  referentiels: [
    {
      id_referentiel: 1,
      nom_referentiel: "dev_data",
      id_promo: "dev_web",
      etat: "actif",
    },
    {
      id_referentiel: 2,
      nom_referentiel: "dev_web",
      id_promo: 2,
      etat: "actif",
    },
    {
      id_referentiel: 3,
      nom_referentiel: "ref_dig",
      id_promo: 2,
      etat: "actif",
    },
  ],
  // referentiels: [
  //    { id: 1, nom: "REf_dig" , description : "Description" , image : "image.jpg"},
  //    { id: 2, nom: "web" , description : "Description" , image : "image.jpg"},
  //    { id: 3, nom: "Dev_data"  , description : "Description" , image : "image.jpg"},
  //    { id: 4, nom: "Hackeuse" , description : "Description" , image : "image.jpg"},
  //    { id: 5, nom: "AWS" , description : "Description" , image : "image.jpg"},
  //  ],
};

// Sélectionner le bouton "Créer nouvel apprenant"
const btnNouvelAp = document.getElementById("btnNouvelAp");
const prenom = document.getElementById("prenom");
const nom = document.getElementById("nom");
const telephone = document.getElementById("telephone");
const dateNaissance = document.getElementById("dateNaissance");
const cni = document.getElementById("cni");
const sexe = document.getElementById("sexe");
const email = document.getElementById("email");
const lieuNaissance = document.getElementById("lieuNaissance");
const referentiel = document.getElementById("id_referentiel");
const promo = document.getElementById("id_promo");
const image = document.querySelector("#image");
const imageEtudiant = document.getElementById("imageEtudiant");

// Fonction pour afficher un message d'erreur sous un champ
function afficherMessageErreur(champ, message) {
  const messageErreur = document.createElement("div");
  messageErreur.classList.add("erreur-message");
  messageErreur.textContent = message;
  messageErreur.style.color = "red";
  champ.parentNode.appendChild(messageErreur);
}

// Fonction pour valider le champ nom ou prénom
function validerNomPrenom(champ, nomChamp) {
  const valeur = champ.value.trim();
  if (valeur === "") {
    afficherMessageErreur(champ, nomChamp + " est obligatoire");
    return false;
  } else if (!/^[a-zA-Z]{5,20}$/.test(valeur)) {
    afficherMessageErreur(
      champ,
      nomChamp +
      " doit contenir uniquement des lettres (minimum 5 caractères et maximum 20 caractères)"
    );
    return false;
  }
  return true;
}

// Fonction pour valider le champ téléphone
function validerTelephone(champ) {
  const valeur = champ.value.trim();
  if (valeur === "") {
    afficherMessageErreur(champ, "Téléphone est obligatoire");
    return false;
  } else if (!/^\d{9}$/.test(valeur)) {
    afficherMessageErreur(
      champ,
      "Téléphone doit contenir exactement 9 chiffres"
    );
    return false;
  }
  return true;
}

// Fonction pour valider le champ CNI
function validerCNI(champ) {
  const valeur = champ.value.trim();
  if (valeur === "") {
    afficherMessageErreur(champ, "N° CNI est obligatoire");
    return false;
  } else if (!/^\d{1,16}$/.test(valeur)) {
    afficherMessageErreur(
      champ,
      "N° CNI doit contenir uniquement des chiffres (maximum 16 chiffres)"
    );
    return false;
  }
  return true;
}

// Fonction pour valider le champ lieu de naissance
function validerLieuNaissance(champ) {
  const valeur = champ.value.trim();
  if (valeur === "") {
    afficherMessageErreur(champ, "Lieu de Naissance est obligatoire");
    return false;
  } else if (!/^[a-zA-Z]+$/.test(valeur)) {
    afficherMessageErreur(
      champ,
      "Lieu de Naissance doit contenir uniquement des lettres"
    );
    return false;
  }
  return true;
}

// Fonction pour valider l'adresse email
function validerEmail(champ) {
  const valeur = champ.value.trim();
  if (valeur === "") {
    afficherMessageErreur(champ, "Email est obligatoire");
    return false;
  } else if (!/^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(valeur)) {
    afficherMessageErreur(champ, "Email n'est pas valide");
    return false;
  }
  return true;
}

image.addEventListener("input", () => {
  imageEtudiant.src = image.value;
});

// événemant click sur le bouton nouveau
btnNouvelAp.addEventListener("click", (e) => {
  e.preventDefault();

  // Supprimer les messages d'erreur précédents
  const messagesErreurs = document.querySelectorAll(".erreur-message");
  messagesErreurs.forEach(function (message) {
    message.remove();
  });

  // Valider chaque champ du formulaire
  const nomValide = validerNomPrenom(document.getElementById("nom"), "Nom");
  const prenomValide = validerNomPrenom(
    document.getElementById("prenom"),
    "Prénom"
  );
  const telephoneValide = validerTelephone(
    document.getElementById("telephone")
  );
  const cniValide = validerCNI(document.getElementById("cni"));
  const lieuNaissanceValide = validerLieuNaissance(
    document.getElementById("lieuNaissance")
  );
  const emailValide = validerEmail(document.getElementById("email"));

  // Si tous les champs sont valides, ajouter l'apprenant
  if (
    nomValide &&
    prenomValide &&
    telephoneValide &&
    cniValide &&
    lieuNaissanceValide &&
    emailValide
  ) {
    // imageEtudiant.src = image.value;
    const nouvelAp = {
      id_etudiant: DB.etudiants.length + 1,
      image: image.value,
      prenom: prenom.value,
      nom: nom.value,
      telephone: telephone.value,
      date_naissance: dateNaissance.value,
      numero_carte_identite: cni.value,
      sexe: sexe.value,
      email: email.value,
      lieuNaissance: lieuNaissance.value,
      referentiel: referentiel.value,
      promo: promo.value,
    };
    DB.etudiants.push(nouvelAp);
    // console.log(DB);
    afficherApprenants();
  }
});



// recherche par nom ou par prenom
const searchInput = document.getElementById("searchInput");
let tableauGlobalInitial = [...DB.etudiants];
document.getElementById("searchInput").addEventListener("input", (e) => {
  let valeurSaisie = e.target.value.trim();
  let nouvelleTailleSaisie = valeurSaisie.length;

  if (nouvelleTailleSaisie > 2) {
    const tableFilter = DB.etudiants.filter((item) => {
      return (
        item.nom.toLowerCase().includes(valeurSaisie.toLowerCase()) ||
        item.prenom.toLowerCase().includes(valeurSaisie.toLowerCase())
      );
    });

    DB.etudiants = tableFilter;

    // console.log(DB.etudiants);
    // console.log(nouvelleTailleSaisie);

    afficherApprenants();
  } else if (nouvelleTailleSaisie < ancienneTailleSaisie) {
    DB.etudiants = [...tableauGlobalInitial];

    // console.log(DB.etudiants);
    // console.log(nouvelleTailleSaisie);

    afficherApprenants();
  }

  ancienneTailleSaisie = nouvelleTailleSaisie;
});

// Sélectionner le tableau HTML
const tableauApprenants = document.querySelector(".line5 tbody");
let apprenantsParPage = 5;
let pageActuelle = 1;

let apprenantEnCours = null;
let isEditing = false;

// Fonction pour afficher les apprenants dans le tableau HTML
function afficherApprenants() {
  const indiceDebut = (pageActuelle - 1) * apprenantsParPage;
  const indiceFin = indiceDebut + apprenantsParPage;

  tableauApprenants.innerHTML = "";

  // Parcourir tous les apprenants dans DB.etudiants
  DB.etudiants.slice(indiceDebut, indiceFin).forEach(function (apprenant) {
    const nouvelleLigne = document.createElement("tr");
    nouvelleLigne.classList.add("line");

    // Ajouter les cellules pour chaque propriété de l'apprenant
    const cellules = [
      "image",
      "nom",
      "prenom",
      "email",
      "sexe",
      "telephone",
      "referentiel",
    ];
    cellules.forEach(function (prop) {
      const nouvelleCellule = document.createElement("td");
      nouvelleCellule.classList.add("bloc");
      const nouvelleDiv = document.createElement("div");
      nouvelleDiv.classList.add("col-bas");
      if (prop === "image") {
        // Si c'est la propriété "image"
        // Créer un élément img
        const imgElement = document.createElement("img");
        // Appliquer la classe "profile-image" pour la taille de l'image de profil
        imgElement.classList.add("profile-image");
        // Définir la source sur le lien de l'image
        imgElement.src = apprenant[prop];
        imgElement.alt = "Photo de l'apprenant"; // Ajouter une description alternative pour l'accessibilité
        nouvelleDiv.appendChild(imgElement);
      } else {
        nouvelleDiv.textContent = apprenant[prop];
      }
      nouvelleCellule.appendChild(nouvelleDiv);
      nouvelleLigne.appendChild(nouvelleCellule);
    });

    // Ajouter la case à cocher pour les actions
    const celluleActions = document.createElement("td");
    celluleActions.classList.add("bloc");
    const divActions = document.createElement("div");
    divActions.classList.add("col-haut");
    const checkbox = document.createElement("input");
    checkbox.setAttribute("type", "checkbox");
    checkbox.dataset.apprenantId = apprenant.id_etudiant; // associer l'apprenant à la case à cocher en utilisant l'attribut de données
    checkbox.id = "my-checkbox-" + apprenant.id_etudiant; // Assurez-vous que chaque ID de case à cocher est unique
    const labelCheckbox = document.createElement("label");
    labelCheckbox.setAttribute("for", "my-checkbox-" + apprenant.id_etudiant);
    divActions.appendChild(checkbox);
    divActions.appendChild(labelCheckbox);
    celluleActions.appendChild(divActions);
    nouvelleLigne.appendChild(celluleActions);

    // Créer le bouton "Modifier" avec une icône à la place du texte
    const boutonModifier = document.createElement("button");
    boutonModifier.classList.add("btn-modifier"); // Ajouter une classe pour le style CSS
    // Utiliser une balise <i> avec la classe Font Awesome correspondant à l'icône de modification
    boutonModifier.innerHTML = '<i class="fas fa-edit"></i>';
    boutonModifier.onclick = function () {
      window.location.href = "#popup"; // Rediriger vers l'ID du modal pour l'afficher
      ouvrirModalModification(apprenant);
      isEditing = true; // Définir isEditing sur true
    };
    divActions.appendChild(boutonModifier);

    nouvelleLigne.setAttribute("data-apprenant-id", apprenant.id_etudiant);
    // Ajouter la nouvelle ligne au tableau
    tableauApprenants.appendChild(nouvelleLigne);
  });

  // Ajouter un événement click sur chaque ligne du tableau

  // const lignes = tableauApprenants.querySelectorAll("tr");
  // lignes.forEach(ligne => {
  //    ligne.addEventListener("click", function (event) {
  //       const ligneClique = event.target.parentNode;
  //       const apprenantId = ligneClique.getAttribute("data-apprenant-id");
  //       const apprenant = DB.etudiants.find(apprenant => apprenant.id_etudiant === parseInt(apprenantId));

  //       // Afficher le modal avec la photo et le code QR de l'apprenant
  //       afficherModalApprenant(apprenant);
  //    });

  // });

  //  Ajouter un événement click sur chaque image  du tableau

  const images = tableauApprenants.querySelectorAll(
    "tr td.bloc div.col-bas img"
  );
  images.forEach((image) => {
    image.addEventListener("click", function (event) {
      const ligneClique = event.target.parentNode.parentNode.parentNode; // Remonter jusqu'à la ligne (tr)
      const apprenantId = ligneClique.getAttribute("data-apprenant-id");
      const apprenant = DB.etudiants.find(
        (apprenant) => apprenant.id_etudiant === parseInt(apprenantId)
      );

      // Afficher le modal avec la photo et le code QR de l'apprenant
      afficherModalApprenant(apprenant);
    });
  });

  ajouterBoutonsPagination();
}


// Fonction pour afficher le modal avec la photo et le code QR de l'apprenant
function afficherModalApprenant(apprenant) {
  const modal = document.getElementById("modal-apprenant");
  modal.style.display = "block";

  const contenuModal = modal.querySelector(".modal-content");
  contenuModal.innerHTML = "";

  // Ajouter la photo de l'apprenant
  const imgElement = document.createElement("img");
  imgElement.src = apprenant.image;
  imgElement.alt = "Photo de l'apprenant";
  contenuModal.appendChild(imgElement);

  // Générer le code QR avec le numéro de téléphone de l'apprenant
  const qrCode = document.createElement("div");
  const telefoneUrl = `tel:${apprenant.telephone.toString()}`;
  const qrCodeUrl = `https://api.qrserver.com/v1/create-qr-code/?size=200x200&data=${encodeURIComponent(
    telefoneUrl
  )}`;
  const qrCodeImg = document.createElement("img");
  qrCodeImg.src = qrCodeUrl;
  qrCodeImg.alt = "Code QR du numéro de téléphone de l'apprenant";
  qrCode.appendChild(qrCodeImg);
  qrCode.id = "qr-code"; // Ajoutez un ID pour référencer le code QR
  contenuModal.appendChild(qrCode);

  // Ajouter un écouteur d'événements pour fermer le modal lorsque l'utilisateur clique en dehors de celui-ci
  modal.addEventListener("click", function (event) {
    if (event.target === modal) {
      modal.style.display = "none";
    }
  });
}

// **************************transfert référentiel****************************************

let checkedData = [];

// Gestionnaire d'événement pour les cases cochées
tableauApprenants.addEventListener("change", function (event) {
  const checkbox = event.target;
  if (checkbox.type === "checkbox") {
    const apprenantId = parseInt(checkbox.dataset.apprenantId); // Récupérer l'ID de l'apprenant à partir de l'attribut de données
    const apprenant = DB.etudiants.find(
      (apprenant) => apprenant.id_etudiant === apprenantId
    );
    const referentiel = apprenant.referentiel; // Récupérer le référentiel associé à cet apprenant

    if (checkbox.checked) {
      // Si la case est cochée, ajouter ses données au tableau
      checkedData.push({ index: apprenantId, referentiel: referentiel });

      // Vérifier si le référentiel coché est présent dans la liste des options du menu déroulant
      const selectRefOptions = document.querySelectorAll(
        "#referentiels option"
      );
      selectRefOptions.forEach((option) => {
        if (option.value === referentiel) {
          option.style.display = "none"; // Cacher l'option correspondante
        }
      });

      // Vérifier si toutes les cases sont cochées
      if (checkedData.length === DB.etudiants.length) {
        alert("Tous les référentiels sont cochés, pas de transfert possible");
      }
    } else {
      // Si la case est décochée, retirer ses données du tableau
      checkedData = checkedData.filter((item) => item.index !== apprenantId);

      // Réafficher l'option correspondante dans le menu déroulant
      const optionToShow = document.querySelector(
        `#referentiels option[value="${referentiel}"]`
      );
      if (optionToShow) {
        optionToShow.style.display = "block";
      }
    }
  }

  console.log(checkedData);
});

// Gestionnaire d'événement pour le changement de sélection dans le menu déroulant
document
  .getElementById("referentiels")
  .addEventListener("change", function (event) {
    const newReferentiel = event.target.value; // Récupérer la nouvelle valeur sélectionnée dans le menu déroulant

    // Mettre à jour le référentiel de tous les apprenants cochés avec le nouveau référentiel sélectionné
    checkedData.forEach((item) => {
      const apprenant = DB.etudiants.find(
        (apprenant) => apprenant.id_etudiant === item.index
      );
      //   apprenant.referentiel = parseInt(newReferentiel);
      apprenant.referentiel = newReferentiel;
    });

    // Afficher un message de confirmation
    alert(
      `Le référentiel de tous les apprenants sélectionnés a été mis à jour avec "${newReferentiel}".`
    );

    // Réinitialiser l'affichage du menu déroulant pour afficher toutes les options
    const selectRefOptions = document.querySelectorAll("#referentiels option");
    selectRefOptions.forEach((option) => {
      option.style.display = "block";
    });

    // Réinitialiser les cases cochées et vider le tableau checkedData
    checkedData = [];
    const checkboxes = document.querySelectorAll('input[type="checkbox"]');
    checkboxes.forEach((checkbox) => {
      checkbox.checked = false;
    });

    afficherApprenants();
    console.log(DB.etudiants); // Vérification dans la console
  });

// Fonction pour ouvrir le modal de modification avec les données de la ligne cliquée
function ouvrirModalModification(apprenant) {
  apprenantEnCours = apprenant;
  const boutonCreerModifier = document.querySelector(".modifier");
  document.getElementById("nom").value = apprenant.nom;
  document.getElementById("prenom").value = apprenant.prenom;
  document.getElementById("email").value = apprenant.email;
  document.getElementById("sexe").value = apprenant.sexe;
  document.getElementById("telephone").value = apprenant.telephone;
  document.getElementById("referentiel").value = apprenant.referentiel;
  document.getElementById("image").value = apprenant.image;
  document.getElementById("dateNaissance").value = apprenant.date_naissance;
  document.getElementById("cni").value = apprenant.numero_carte_identite;
  document.getElementById("lieuNaissance").value = apprenant.lieuNaissance;

  // Modifier le texte du bouton "Créer" en "Modifier"
  boutonCreerModifier.textContent = "Modifier";
}

// Fonction pour modifier l'apprenant
// Fonction pour modifier l'apprenant
function modifierApprenant() {
  const apprenantId = apprenantEnCours.id_etudiant;
  const apprenantRow = document.querySelector(
    `tr[data-apprenant-id="${apprenantId}"]`
  );

  const cellules = [
    "image",
    "nom",
    "prenom",
    "email",
    "sexe",
    "telephone",
    "referentiel",
  ];
  apprenantEnCours.nom = document.getElementById("nom").value;
  apprenantEnCours.prenom = document.getElementById("prenom").value;
  apprenantEnCours.email = document.getElementById("email").value;
  apprenantEnCours.sexe = document.getElementById("sexe").value;
  apprenantEnCours.telephone = document.getElementById("telephone").value;
  apprenantEnCours.referentiel = document.getElementById("referentiel").value;
  apprenantEnCours.image = document.getElementById("image").value;
  apprenantEnCours.date_naissance =
    document.getElementById("dateNaissance").value;
  apprenantEnCours.numero_carte_identite = document.getElementById("cni").value;
  apprenantEnCours.lieuNaissance =
    document.getElementById("lieuNaissance").value;

  // Mettre à jour les informations de l'apprenant dans la ligne correspondante du tableau
  const cellulesRow = apprenantRow.querySelectorAll(".bloc");
  cellules.forEach(function (prop, index) {
    if (prop === "image") {
      cellulesRow[index].querySelector("img").src = apprenantEnCours[prop];
    } else {
      cellulesRow[index].textContent = apprenantEnCours[prop];
    }
  });

  // Réinitialiser le formulaire
  document.getElementById("nom").value = "";
  document.getElementById("prenom").value = "";
  document.getElementById("email").value = "";
  document.getElementById("sexe").value = "";
  document.getElementById("telephone").value = "";
  document.getElementById("referentiel").value = "";
  document.getElementById("image").value = "";
  document.getElementById("dateNaissance").value = "";
  document.getElementById("cni").value = "";
  document.getElementById("lieuNaissance").value = "";
}

const btnNouvelApText = document.getElementById("btnNouvelApText");

// Fonction pour changer le texte du bouton en alternance
function changerTexteBouton() {
  if (btnNouvelApText.textContent === "+ Créer nouvel apprenant") {
    btnNouvelApText.textContent = "Modifier";
  } else {
    btnNouvelApText.textContent = "+ Créer nouvel apprenant";
  }
}

// Ajouter un écouteur d'événements pour changer le texte du bouton en alternance lorsqu'il est cliqué
document
  .getElementById("btnNouvelAp")
  .addEventListener("click", changerTexteBouton);

// funtion pour pagination
function ajouterBoutonsPagination() {
  const totalApprenants = DB.etudiants.length;
  const totalPages = Math.ceil(totalApprenants / apprenantsParPage);

  const paginationContainer = document.getElementById("pagination");
  paginationContainer.innerHTML = "";

  if (totalPages > 1) {
    if (pageActuelle > 1) {
      const boutonPrecedent = creerBoutonPagination(
        "Précédent",
        pageActuelle - 1
      );
      paginationContainer.appendChild(boutonPrecedent);
    }

    for (let i = 1; i <= totalPages; i++) {
      const boutonPage = creerBoutonPagination(i, i);
      paginationContainer.appendChild(boutonPage);
    }

    if (pageActuelle < totalPages) {
      const boutonSuivant = creerBoutonPagination("Suivant", pageActuelle + 1);
      paginationContainer.appendChild(boutonSuivant);
    }
  }
}
function creerBoutonPagination(texte, numeroPage) {
  const bouton = document.createElement("a");
  bouton.href = "#";
  bouton.classList.add("page-link");
  bouton.textContent = texte;
  bouton.addEventListener("click", function () {
    pageActuelle = numeroPage;
    afficherApprenants();
  });
  return bouton;
}
function changerNombreItems(nouveauNombre) {
  apprenantsParPage = nouveauNombre;
  pageActuelle = 1; // Revenir à la première page lors du changement du nombre d'éléments par page
  afficherApprenants();
}
afficherApprenants();

// editer sur chaque cellule du tableau
tableauApprenants.addEventListener("dblclick", function (event) {
  const celluleCible = event.target.closest("td");
  if (celluleCible) {
    // Rendre la cellule éditable
    celluleCible.setAttribute("contenteditable", "true");
    celluleCible.style.fontSize = "20px";
    celluleCible.style.backgroundColor = "rgba(0, 0, 0, 0.1)";
    celluleCible.type = "text";
    celluleCible.focus(); // Focus sur la cellule pour que l'utilisateur puisse commencer à éditer immédiatement

    celluleCible.addEventListener("keydown", function (event) {
      if (event.key === "Enter") {
        celluleCible.removeAttribute("contenteditable");
        sauvegarderModification(celluleCible); // Appel de la fonction pour sauvegarder la modification
        celluleCible.style.backgroundColor = "transparent";
      }
    });
  }
});

// Fonction pour sauvegarder les modifications apportées à une cellule
function sauvegarderModification(cellule) {
  const ligne = cellule.closest("tr"); // Obtenir la ligne parente de la cellule
  const indexApprenant = Array.from(ligne.parentNode.children).indexOf(ligne); // Obtenir l'index de l'apprenant dans le tableau
  const colonne = Array.from(cellule.parentNode.children).indexOf(cellule); // Obtenir l'index de la colonne de la cellule éditée

  // Mettre à jour les données de l'apprenant modifié
  const valeurModifiee = cellule.textContent.trim();
  if (colonne === 1) {
    DB.etudiants[indexApprenant].nom = valeurModifiee;
  } else if (colonne === 2) {
    DB.etudiants[indexApprenant].prenom = valeurModifiee;
  } else if (colonne === 3) {
    DB.etudiants[indexApprenant].email = valeurModifiee;
  } else if (colonne === 4) {
    DB.etudiants[indexApprenant].sexe = valeurModifiee;
  } else if (colonne === 5) {
    DB.etudiants[indexApprenant].telephone = valeurModifiee;
  } else if (colonne === 6) {
    DB.etudiants[indexApprenant].referentiel = valeurModifiee;
  }

  // Mettre à jour les données dans le stockage local
  localStorage.setItem("data", JSON.stringify(DB));
}

// Récupérer les en-têtes de colonne
const nomHeader = document.getElementById("nom-header");
const prenomHeader = document.getElementById("prenom-header");

// Définir une variable pour suivre l'état du tri
let triCroissantNom = true;
let triCroissantPrenom = true;

// Ajouter des écouteurs d'événements pour le tri croissant et décroissant
nomHeader.addEventListener("click", () => {
  trierDonnees("nom", triCroissantNom);
  triCroissantNom = !triCroissantNom; // Inverser l'état du tri
});

prenomHeader.addEventListener("click", () => {
  trierDonnees("prenom", triCroissantPrenom);
  triCroissantPrenom = !triCroissantPrenom; // Inverser l'état du tri
});

// Fonction de tri des données en fonction de la colonne spécifiée
function trierDonnees(colonne, croissant) {
  // Récupérer les données des étudiants
  const etudiants = DB.etudiants;

  // Trier les données en fonction de la colonne spécifiée
  switch (colonne) {
    case "nom":
      etudiants.sort((a, b) => {
        if (croissant) {
          return a.nom.localeCompare(b.nom); // Tri croissant par nom
        } else {
          return b.nom.localeCompare(a.nom); // Tri décroissant par nom
        }
      });
      break;
    case "prenom":
      etudiants.sort((a, b) => {
        if (croissant) {
          return a.prenom.localeCompare(b.prenom); // Tri croissant par prénom
        } else {
          return b.prenom.localeCompare(a.prenom); // Tri décroissant par prénom
        }
      });
      break;
    default:
      break;
  }

  // Afficher les données triées
  afficherApprenants();
}

// *****************************transférer********************************

// *******************************************promotion**********************************************
// affichicher tableau promo
const promotions = document.querySelector("#promo");
const containerPromo = document.querySelector(".containerPromo");
const containerApprenant = document.querySelector(".container-table");
const btnNouvelle = document.querySelector("#nouvelle");
const popupPromo = document.querySelector("#popupPromo");
containerPromo.style.display = "none";

// Afficher la liste des promotions
promotions.addEventListener("click", () => {
  containerPromo.style.display = "block";
  containerApprenant.style.display = "none";
  btnNouveau.style.display = "none";
  btnNouvelle.style.display = "block";
  popupPromo.style.display = "none";
});

// afficher tableau apprenant
const apprenants = document.querySelector("#apprenants");
const btnNouveau = document.querySelector("#nouveau");

apprenants.addEventListener("click", () => {
  containerPromo.style.display = "none";
  containerApprenant.style.display = "block";
  btnNouvelle.style.display = "none";
  btnNouveau.style.display = "block";
  popupPromo.style.display = "none";
});

// modalajouter une promo
const closeModalBtn = document.getElementById("closeModal");
btnNouvelle.addEventListener("click", () => {
  popupPromo.style.display = "block";

  window.addEventListener("click", function (event) {
    if (event.target == popupPromo) {
      //   closeModal();
    }
  });
});
function closeModal() {
  popupPromo.style.display = "none";
}
//  empecher la fermuture en cliquant en dehors du modal
closeModalBtn.addEventListener("click", function (event) {
  event.stopPropagation();
  popupPromo.style.display = "none";
});

const tbodyPromo = document.querySelector("#tbody-promo");

document.querySelector("#promoForm").addEventListener("submit", (e) => {
  e.preventDefault();

  const libelle = document.querySelector("#libellePromo");
  const dateDebut = document.querySelector("#dateDebutPromo");
  const dateFin = document.querySelector("#dateFinPromo");

  const nouvellePromotion = {
    id_promo: DB.promotions.length + 1,
    nom: libelle.value,
    dateDebut: dateDebut.value,
    dateFin: dateFin.value,
    etat: false,
  };
  DB.promotions.push(nouvellePromotion);
  console.log(DB.promotions);

  // Réinitialiser les champs du formulaire
  document.querySelector("#popupPromo form").reset();

  // Fermer le modal
  closeModal();

  // Mettre à jour le tableau HTML
  afficherPromotions();
});

function afficherPromotions() {
  const containerPromo = document.querySelector(".containerPromo table tbody");
  containerPromo.innerHTML = "";

  DB.promotions.forEach((promotion) => {
    const tr = document.createElement("tr");
    tr.classList.add("line");
    tr.innerHTML = `
       <td class="bloc">
         <div class="col-bas" style="color: rgb(29, 109, 29)">
           ${promotion.nom}
         </div>
       </td>
       <td class="bloc">
         <div class="col-bas" style="color: rgb(29, 109, 29)">
           ${promotion.dateDebut}
         </div>
       </td>
       <td class="bloc">
         <div class="col-bas email">${promotion.dateFin}</div>
       </td>
       <td class="bloc action">
         <div class="col-haut"></div>
         <button class="btn-activer ${promotion.etat ? "active" : ""
      }" data-id="${promotion.id_promo}">${promotion.etat ? "Active" : "Désactive"
      }</button>
       </td>
     `;
    containerPromo.appendChild(tr);
  });

  // ajouter un écouteur d'événement sur les boutons d'activation/désactivation
  const boutonsActiver = document.querySelectorAll(".btn-activer");
  boutonsActiver.forEach((bouton) => {
    bouton.addEventListener("click", function () {
      const idPromotion = this.dataset.id;
      const promotion = DB.promotions.find(
        (p) => p.id_promo === parseInt(idPromotion)
      );

      // désactiver toutes les promotions
      DB.promotions.forEach((p) => {
        p.etat = false;
      });

      // activer la promotion sélectionnée
      promotion.etat = true;

      // mettre à jour l'affichage du tableau
      afficherPromotions();
    });
  });
}

afficherPromotions();
