def main():

    topay = int
    payvip = 1000
    paycorn = 500

    age = int(input("Entrez votre âge: "))
    if age < 18:
        print("Vous êtes mineur ! Ticket mineur :3.000f FCA")  
        topay = 3000   
    elif age >= 18:
        print("Vous êtes majeur ! Ticket majeur :4.000f FCA") 
        topay = 4000   

    vip = input("Voulez-vous une place vip ? (oui/non): ")

    if vip.lower() == "oui":
        print("Place VIP pour 1000f CFA plus la somme du ticket")
        topay += payvip

    popscorn = input("Souhaitez-vous prendre du pops corn Prix = 500F ? (oui/non): ")

    if popscorn.lower() == "oui":
        topay += paycorn
        print("Vous avez choisi le pops corn, prix = 500F ! ")
        print("La somme à payer est de ",topay,"F CA.")    
    else:
        print("Aucun pops corn n'a été acheté.")
        print("La somme à payer est de ",topay,"F CA.")
    print("Merci et bonne séance à vous !!!")

if __name__ == "__main__":
    main()