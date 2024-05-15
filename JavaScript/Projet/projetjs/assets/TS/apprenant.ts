enum User {
    matricule = "MAT-1028215",
    nom = "Diop",
    prenom = "Seydina Mouhammad",
    email = "mouhammad.diop@gmail.com",
    password = "seydiop@123"
}

const user2: User = User.prenom;

console.log(user2)

let description: string = "Ceci est un test pour les strings"

let description2: string = "(la suite de la description )"

console.log(description + description2)

let longueur: string = "Fonctions sur les strings";

console.log(longueur.length); // Output: 25

let lettre: string = "Hello, There!";

console.log(lettre.charAt(0)); // Output: H


let sequence: string = "Hello, world!";

console.log(sequence.substring(0, 5)); // Output: Hello


let myString1: string = "Hello, world!";

console.log(myString1.toUpperCase()); // Output: HELLO, WORLD!
console.log(myString1.toLowerCase()); // Output: hello, world!


let myString4: string = "Hello, world!";

console.log(myString4.indexOf("world")); // Output: 7
console.log(myString4.lastIndexOf("o")); // Output: 8


let myString7: string = "apple,banana,grape";

let fruits: string[] = myString7.split(",");
console.log(fruits); // Output: ["apple", "banana", "grape"]


let myString: string = "Hello, world!";

let newString: string = myString.replace("world", "universe");
console.log(newString); // Output: Hello, universe!


