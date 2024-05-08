
// La fonction qui permet de soumettre le formulaire
function soumettreFormulaire() {
    if (validerFormulaire()) {
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

        BASEDEDONNEE.etudiant.push(newUser);
        afficherToutLesApprenants();
    }
}



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
            errorSpan.textContent = "";
            input.classList.remove("invalid");
        }
    });

    // Ajoutez ici d'autres validations spécifiques si nécessaire

    return isValid;
}





/// Note base de donnée
const BASEDEDONNEE = {
    etudiant: [],
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