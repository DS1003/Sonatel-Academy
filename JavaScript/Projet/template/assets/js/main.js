let profile = document.querySelector('.header .profile');

document.querySelector('#user-btn').onclick = () => {
   profile.classList.toggle('active');
   search.classList.remove('active');
}

let toggleBtn = document.getElementById('toggle-btn');
let body = document.body;
let darkMode = localStorage.getItem('dark-mode');

const enableDarkMode = () => {
   toggleBtn.classList.replace('fa-sun', 'fa-moon');
   body.classList.add('dark');
   localStorage.setItem('dark-mode', 'enabled');
}

const disableDarkMode = () => {
   toggleBtn.classList.replace('fa-moon', 'fa-sun');
   body.classList.remove('dark');
   localStorage.setItem('dark-mode', 'disabled');
}

if (darkMode === 'enabled') {
   enableDarkMode();
}

toggleBtn.onclick = (e) => {
   darkMode = localStorage.getItem('dark-mode');
   if (darkMode === 'disabled') {
      enableDarkMode();
   } else {
      disableDarkMode();
   }
}



function soumettreFormulaire() {
   /* if (validerFormulaire()) { */
       const form = document.querySelector("#apprenantForm");
       const formData = new FormData(form);

       const newUser = {
           image: formData.get("image"),
           prenom: formData.get("prenom"),
           nom: formData.get("nom"),
           email: formData.get("email"),
           telephone: formData.get("telephone"),
           sexe: formData.get("sexe"),
           dateNaissance: formData.get("dateNaissance"),
           lieuNaissance: formData.get("lieuNaissance"),
           cni: formData.get("cni"),
           referentiel: formData.get("referentiel"),
           promo: formData.get("promo")
       }

       BASEDEDONNEE.etudiant.push(newUser); // Enregistrer le nouvel apprenant dans BASEDEDONNEE
       afficherToutLesApprenants(); // Afficher tous les apprenants, y compris le nouvel apprenant
   /* } */
}


// Sélection du formulaire
const form = document.getElementById("apprenantForm");

// Ajout d'un événement de soumission au formulaire
form.addEventListener("submit", function(event) {
    event.preventDefault(); // Empêche le comportement par défaut du formulaire

    // Appel de la fonction pour soumettre le formulaire
    soumettreFormulaire();
});



// Fonction qui permet d'afficher un seul apprenant
function afficherUnApprenant(user) {

   const model = `
      <tr class="line">
         <td class="bloc">
            <div class="col-bas"><img src=${user.image} width="30px" /></div>
         </td>
         <td class="bloc">
            <div class="col-bas" style="color: rgb(29, 109, 29)">${user.nom}</div>
         </td>
         <td class="bloc">
            <div class="col-bas" style="color: rgb(29, 109, 29)">${user.prenom}</div>
         </td>
         <td class="bloc">
            <div class="col-bas email">${user.email}</div>
         </td>
         <td class="bloc">
            <div class="col-bas">${user.sexe}</div>
         </td>
         <td class="bloc">
            <div class="col-bas">${user.telephone}</div>
         </td>
         <td class="bloc">
            <div class="col-bas">${BASEDEDONNEE.referentiel.find(ref => ref.id == user.referentiel).libelle}</div>
         </td>
         <td class="bloc">
            <div class="col-haut"></div>
            <input type="checkbox" id="my-checkbox-0" />
            <label for="my-checkbox-0"></label>
         </td>
      </tr>
   `;

   // On retourn le model
   return model;
}


// On récupérére la où on doit afficher les apprenants
const bobyApprenant = document.getElementById("containerApprenant");
console.log(bobyApprenant);

// Fonction qui permet d'afficher tout les apprenants
function afficherToutLesApprenants() {

   // On enléve le contenue de là où on doit mettre les apprenants
   bobyApprenant.innerHTML = "";

   // On boucle sur la liste des apprenants
   BASEDEDONNEE.etudiant.forEach(etudiant => {
       bobyApprenant.insertAdjacentHTML("afterbegin", afficherUnApprenant(etudiant));
   });
}


function validerFormulaire() {
   const form = document.getElementById("apprenantForm");
   const inputs = form.querySelectorAll("input, select");
   let isValid = true;

   inputs.forEach(input => {
       const errorSpan = document.getElementById(`${input.id}-error`);
       if (input.hasAttribute("required") && !input.value.trim()) {
           isValid = false;
           errorSpan.textContent = "Ce champ est requis.";
           input.classList.add("invalid");
       } else {
           errorSpan.textContent = ""; // Effacer le message d'erreur
           input.classList.remove("invalid");
       }
   });

   // Ajoutez ici d'autres validations spécifiques si nécessaire

   return isValid;
}


/// Note base de donnée
const BASEDEDONNEE = {
   etudiant: [

   ],
   referentiel: [
       {
           id: "web",
           libelle: "Dev Web"
       },
       {
           id: "dig",
           libelle: "Referent Digital"
       },
       {
           id: "hack",
           libelle: "Hackeuse"
       },
       {
           id: "data",
           libelle: "Dev Data"
       },
       {
           id: "aws",
           libelle: "AWS"
       }
   ],
   promotion: [
       {
           id: "p1",
           libelle: "Promotion 1",
           debut: "2019-02-01",
           fin: "2019-10-01",
       }
   ]
}



// On appelle la fonction qui permet d'afficher tout les étudiants
afficherToutLesApprenants();


/* //Recherche par nom et prénom sur les apprenants
function recherche() {
   const apprenants = Map(BASEDEDONNEE);
   const recherche = document.getElementById("recherche").value;
   const resultat = document.getElementById("resultat");
   resultat.innerHTML = "";
   for (let i = 0; i < apprenants.length; i++) {
       if (apprenants[i].nom.includes(recherche) || apprenants[i].prenom.includes(recherche)) {
           resultat.insertAdjacentHTML("afterbegin", afficherUnApprenant(apprenants[i]));
       }
   }
   if (recherche == "") {
       afficherToutLesApprenants();
   }
   return false;
   console.log(apprenants);
   console.log(recherche);
   console.log(resultat);
   console.log(BASEDEDONNEE.etudiant);
   console.log(BASEDEDONNEE.etudiant.find(etudiant => etudiant.nom.includes(recherche)));
   
} */

// Sélection de l'élément de recherche
const searchInput = document.querySelector(".line3 input[name='search']");

// Ajout d'un écouteur d'événement pour le champ de recherche
searchInput.addEventListener("input", function() {
    const searchTerm = searchInput.value.trim().toLowerCase(); // Terme de recherche en minuscules

    // Filtrer la liste des étudiants
    const filteredStudents = BASEDEDONNEE.etudiant.filter(student => {
        // Vérifier si le nom ou le prénom de l'étudiant contient le terme de recherche
        return student.nom.toLowerCase().includes(searchTerm) || student.prenom.toLowerCase().includes(searchTerm);
    });

    // Afficher les étudiants filtrés
    afficherEtudiantsFiltres(filteredStudents);
});

// Fonction pour afficher les étudiants filtrés
function afficherEtudiantsFiltres(filteredStudents) {
    // Effacer le contenu actuel du conteneur des étudiants
    bobyApprenant.innerHTML = "";

    // Boucler à travers les étudiants filtrés et les afficher
    filteredStudents.forEach(student => {
        bobyApprenant.insertAdjacentHTML("afterbegin", afficherUnApprenant(student));
    });
}



// -------------------------------------------- Vendredi tasks ------------------------------------------
const students = document.querySelector('.apprenantTable');
const promos = document.querySelector('.promoTable');
const studentsMenuItem = document.querySelector('.navbar a:nth-child(2)');
const promosMenuItem = document.querySelector('.navbar a:nth-child(3)');

// recupéré le boutton addbtn et modifier son text content
const addBtn = document.querySelector('.addBtn');
const popup = document.querySelector('.modal');


promosMenuItem.addEventListener('click', function(e) {
   e.preventDefault();
   students.style.display = 'none';
   promos.style.display = 'block';
   addBtn.textContent = '+ Nouvelle';
});


studentsMenuItem.addEventListener('click', function(e) {
   e.preventDefault();
   students.style.display = 'block';
   promos.style.display = 'none';
   addBtn.textContent = '+ Nouveau';
});

//fonction pour afficher le popup lorsque tu clique sur le button addBtn 
addBtn.addEventListener('click', function(e) {
   e.preventDefault();
   popup.style.display = 'block';
   // Verifier si le text-content de addBtn si c'est égale à "Nouveau" display: block; le form apprenantForm si c'est "Nouvelle" display: block; le form addpromoForm
   if (addBtn.textContent === '+ Nouveau') {
      document.querySelector('#apprenantForm').style.display = 'block';
      document.querySelector('#addpromoForm').style.display = 'none';
   } else if (addBtn.textContent === '+ Nouvelle'){
      document.querySelector('#apprenantForm').style.display = 'none';
      document.querySelector('#addpromoForm').style.display = 'block';
   }
});


// Sélection de tous les éléments de fermeture avec la classe ".close"
const closeButtons = document.querySelectorAll('.close');

// Ajout d'un écouteur d'événements pour chaque bouton de fermeture
closeButtons.forEach(closeButton => {
    closeButton.addEventListener('click', function(e) {
        e.preventDefault();
        const popup = this.closest('.modal');
        popup.style.display = 'none';
    });
});
   