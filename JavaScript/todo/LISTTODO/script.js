// Variables globales
var addBtn = document.querySelector(".add");
var delBtn = document.querySelector(".del");
var modal = document.getElementById("myModal");
var closeBtn = document.querySelector(".close");
var addTaskBtn = document.getElementById("addTaskBtn");
var taskList = document.getElementById("taskList");
const dateSpan = document.getElementById("date");

/* PARTIE POUR AJOUTER LA DATE ACTUELLE */

// Sélectionner l'élément input de type date
const dateInput = document.getElementById("dateInput");
// Obtenir la date actuelle
const currentDate = new Date();
// Formater la date au format ISO (AAAA-MM-JJ)
const year = currentDate.getFullYear();
let month = currentDate.getMonth() + 1; // Les mois commencent à 0
if (month < 10) {
  month = "0" + month; // Ajouter un zéro devant si le mois est inférieur à 10
}
let day = currentDate.getDate();
if (day < 10) {
  day = "0" + day; // Ajouter un zéro devant si le jour est inférieur à 10
}
// Définir la valeur de l'élément input de type date
dateInput.value = `${year}-${month}-${day}`;

/* FIN */

// Ajouter un écouteur d'événement pour le changement de valeur de l'input
dateInput.addEventListener("change", function () {
  // Obtenir la valeur de la date sélectionnée dans l'input
  const selectedDate = dateInput.value;
  // Mettre à jour le texte du span avec la nouvelle date
  dateSpan.textContent = selectedDate;
  showTasksByDate(); // Appel de la fonction pour afficher les tâches par date
});

// Afficher le modal
addBtn.onclick = function () {
  modal.style.display = "block";
};

// Fermer le modal
closeBtn.onclick = function () {
  modal.style.display = "none";
};

// Quand on clique en dehors du modal
window.onclick = function (event) {
  if (event.target == modal) {
    modal.style.display = "none";
  }
};

// Ajouter une tâche
addTaskBtn.onclick = function () {
  addTask();
  showTasksByDate(); // Appel de la fonction pour afficher les tâches par date
  disableAddButton(); // Appel de la fonction pour désactiver le bouton si nécessaire
};

// Charger les tâches depuis le stockage local lors du chargement de la page
window.onload = function () {
  var tasks = getTasksFromLocalStorage();
  tasks.forEach(function (task) {
    addTaskToDOM(task);
  });
};

// Fonction pour afficher les tâches par date
function showTasksByDate() {
  // Obtenir la date sélectionnée
  const selectedDate = dateInput.value;
  
  // Récupérer toutes les tâches depuis le stockage local
  const tasks = getTasksFromLocalStorage() || [];

  // Effacer la liste des tâches affichées
  taskList.innerHTML = "";

  // Filtrer les tâches pour n'afficher que celles qui correspondent à la date sélectionnée
  const tasksByDate = tasks.filter(task => task.date === selectedDate);

  // Ajouter les tâches filtrées au DOM
  tasksByDate.forEach(task => {
    addTaskToDOM(task);
  });
}

// Fonction pour ajouter une nouvelle tâche
function addTask() {
  var taskInput = document.getElementById("taskInput").value;
  var timeInput = document.getElementById("timeInput").value;

  // Vérifier si les champs sont valides
  if (!error(taskInput, timeInput)) {
    return;
  }

  // Obtenir la date sélectionnée
  const selectedDate = dateInput.value;

  // Créer un objet représentant la nouvelle tâche
  var newTask = {
    content: taskInput,
    time: timeInput,
    date: selectedDate // Ajout de la date à la tâche
  };

  // Récupérer les tâches existantes depuis le stockage local
  var tasks = getTasksFromLocalStorage() || []; 

  // Ajouter la nouvelle tâche au tableau
  tasks.push(newTask);

  // Sauvegarder les tâches mises à jour dans le stockage local
  saveTasksToLocalStorage(tasks);

  // Ajouter la tâche au DOM
  addTaskToDOM(newTask);

  // Cacher le modal
  modal.style.display = "none";
}

// Fonction pour modifier une tâche
function editTask(taskElement) {
  var taskContent = taskElement.querySelector('.task-content');
  var currentContent = taskContent.innerText;

  // Créer un champ de saisie modifiable
  var input = document.createElement('input');
  input.type = 'text';
  input.value = currentContent;

  // Remplacer le contenu de la tâche par le champ de saisie
  taskContent.innerHTML = '';
  taskContent.appendChild(input);

  // Focus sur le champ de saisie
  input.focus();

  // Ajouter un gestionnaire d'événements pour la touche "Enter"
  input.addEventListener('keypress', function(event) {
    if (event.key === 'Enter') {
      saveEditedTask(taskElement, currentContent, input.value);
    }
  });
}

// Fonction pour mettre à jour une tâche dans le stockage local
function updateTaskInLocalStorage(oldValue, newValue) {
  var tasks = getTasksFromLocalStorage();
  tasks.forEach(function(task) {
    if (task.content === oldValue) {
      task.content = newValue;
    }
  });
  saveTasksToLocalStorage(tasks);
}

// Fonction pour sauvegarder les modifications apportées à une tâche
function saveEditedTask(taskElement, oldContent, newContent) {
  // Mettre à jour le contenu de la tâche
  taskElement.querySelector('.task-content').innerText = newContent;

  // Mettre à jour les tâches dans le stockage local
  updateTaskInLocalStorage(oldContent, newContent);
}

// Fonction pour ajouter une tâche au DOM à partir des données du stockage local
function addTaskToDOM(task) {
  var newTask = createTaskElement(task);
  taskList.appendChild(newTask);
}

function error(taskInput, timeInput) {
  var hasError = false;

  // Vérifier le champ de la tâche
  if (taskInput.trim() === "") {
    alert("Veuillez entrer une tâche");
    hasError = true;
  }

  // Vérifier le champ de l'heure
  if (timeInput.trim() === "") {
    alert("Veuillez entrer une heure");
    hasError = true;
  }

  return !hasError;
}

// Ajouter un écouteur d'événement pour le changement de valeur de la liste déroulante "allTask"
document.getElementById("allTask").addEventListener("change", function () {
  toggleAllTasks(this.checked); // Appel de la fonction pour cocher ou décocher toutes les tâches
});

// Fonction pour cocher ou décocher toutes les tâches en fonction de l'état de la case à cocher "allTask"
function toggleAllTasks(checked) {
  var checkboxes = document.querySelectorAll('.list input[type="checkbox"]');
  checkboxes.forEach(function (checkbox) {
    checkbox.checked = checked;
  });
}

// Modifier la fonction de suppression pour supprimer toutes les tâches lorsque l'option "allTask" est sélectionnée
delBtn.onclick = function () {
  var checkboxes = document.querySelectorAll('.list input[type="checkbox"]');
  checkboxes.forEach(function (checkbox) {
    if (checkbox.checked || document.getElementById("allTask").checked) {
      // Supprimer la tâche du DOM
      checkbox.parentElement.remove();

      // Récupérer les tâches depuis le stockage local
      var tasks = getTasksFromLocalStorage();

      // Supprimer toutes les tâches si l'option "allTask" est sélectionnée
      if (document.getElementById("allTask").checked) {
        tasks = [];
      } else {
        // Trouver l'index de la tâche à supprimer dans le tableau
        var index = tasks.findIndex(function (task) {
          return (
            task.content ===checkbox.parentElement.querySelector(".task-content").innerText
          );
        });

        // Supprimer la tâche du tableau
        tasks.splice(index, 1);
      }

      // Sauvegarder les tâches mises à jour dans le stockage local
      saveTasksToLocalStorage(tasks);

      disableAddButton(); // Appel de la fonction pour désactiver le bouton si nécessaire
    }
  });
};

// Fonction pour créer un élément de tâche
function createTaskElement(task) {
  var newTask = document.createElement("div");
  newTask.classList.add("list");

  var checkbox = document.createElement("input");
  checkbox.setAttribute("type", "checkbox");
  newTask.appendChild(checkbox);
  checkbox.classList.add("checkbox");

  var taskContent = document.createElement("div");
  taskContent.classList.add("task-content");
  taskContent.innerText = task.content;
  newTask.appendChild(taskContent);

  var taskTime = document.createElement("input");
  taskTime.classList.add("task-date");
  taskTime.setAttribute("type", "time");
  taskTime.setAttribute("value", task.time);
  taskTime.setAttribute("disabled", "disabled");
  newTask.appendChild(taskTime);

  // Ajout d'un gestionnaire d'événements de clic pour barrer la tâche
  newTask.addEventListener("click", function () {
    newTask.classList.toggle("completed"); // Barre la tâche au clic
  });

  // Ajout d'un gestionnaire d'événements de double-clic pour modifier la tâche
  newTask.addEventListener("dblclick", function () {
    editTask(this); // Appel de la fonction d'édition
  });

  return newTask;
}

// Fonction pour récupérer les tâches depuis le stockage local
function getTasksFromLocalStorage() {
  var tasks = JSON.parse(localStorage.getItem("tasks")) || [];
  return tasks;
}

// Fonction pour sauvegarder les tâches dans le stockage local
function saveTasksToLocalStorage(tasks) {
  localStorage.setItem("tasks", JSON.stringify(tasks));
}

/* Fonction pour griser le bouton ajouter s'il n'y a pas de tâche */
function disableAddButton() {
  if (getTasksFromLocalStorage().length === 0) {
    delBtn.disabled = true; 
  } else {
    delBtn.disabled = false;
  }
}

// Appel initial pour désactiver le bouton si nécessaire lors du chargement de la page
disableAddButton();

// Ajouter un écouteur d'événement pour le changement de valeur du sélecteur de filtre
document.getElementById("filter").addEventListener("change", function () {
  filterTasks();
});

// Fonction pour filtrer les tâches en fonction du critère sélectionné
function filterTasks() {
  const selectedFilter = document.getElementById("filter").value;
  let filteredTasks = [];

  switch (selectedFilter) {
    case "completed":
      filteredTasks = getCompletedTasks();
      break;
    case "uncompleted":
      filteredTasks = getUncompletedTasks();
      break;
    case "ordreAscDesc":
      filteredTasks = getTasksOrderedByAlphabet();
      break;
    case "ordreAscDescReverse":
      filteredTasks = getTasksOrderedByAlphabetReverse();
      break;
    case "heure":
      filteredTasks = getTasksOrderedByTime();
      break;
    default:
      filteredTasks = getTasksFromLocalStorage();
      break;
  }

  // Afficher les tâches filtrées
  displayFilteredTasks(filteredTasks);
}

// Fonction pour obtenir les tâches terminées
function getCompletedTasks() {
  const tasks = getTasksFromLocalStorage();
  return tasks.filter(task => task.completed);
}

// Fonction pour obtenir les tâches non terminées
function getUncompletedTasks() {
  const tasks = getTasksFromLocalStorage();
  return tasks.filter(task => !task.completed);
}

// Fonction pour obtenir les tâches ordonnées par ordre alphabétique
function getTasksOrderedByAlphabet() {
  const tasks = getTasksFromLocalStorage();
  return tasks.slice().sort((a, b) => a.content.localeCompare(b.content));
}

// Fonction pour obtenir les taches ordonnées par ordre alphabétique de Z à A
function getTasksOrderedByAlphabetReverse() {
  const tasks = getTasksFromLocalStorage();
  return tasks.slice().sort((a, b) => b.content.localeCompare(a.content));
}


// Fonction pour obtenir les tâches ordonnées par heure
function getTasksOrderedByTime() {
  const tasks = getTasksFromLocalStorage();
  return tasks.slice().sort((a, b) => a.time.localeCompare(b.time));
}

// Fonction pour afficher les tâches filtrées
function displayFilteredTasks(filteredTasks) {
  // Effacer la liste des tâches affichées
  taskList.innerHTML = "";

  // Ajouter les tâches filtrées au DOM
  filteredTasks.forEach(task => {
    addTaskToDOM(task);
  });
}
