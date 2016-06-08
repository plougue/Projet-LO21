#include "operateurs_instances.h"
#include <sstream>
// OPERATIONS DES OPERATEURS
Pile& Dupliquer::operation(const Pile& P)
{
    Pile &Res = * (new Pile(P));

    Litteral &L = Res.pop();
    Res.push(L);
    Res.push(L);
    return Res;
}

Pile& Drop::operation(const Pile& P)
{
    Pile &Res = * (new Pile(P));
    Litteral &L = Res.pop();
    return Res;
}

Pile& Swap::operation(const Pile& P)
{
    Pile &Res = * (new Pile(P));

    Litteral &L1 = Res.pop();
    Litteral &L2 = Res.pop();
    Res.push(L1);
    Res.push(L2);
    return Res;
}

Pile& Undo::operation(const Pile& P)
{
    Pile &Res = * (new Pile(P));

    Litteral &L1 = Res.pop();
    Litteral &L2 = Res.pop();
    Res.push(L1);
    Res.push(L2);
    return Res;
}

Pile& Clear::operation(const Pile& P)
{
    Pile &Res = * (new Pile(P));
    unsigned int i;
    while (Res.getTaille()>0)
    {
        Res.pop();
        Res.setTaille(Res.getTaille()-1);

    }
    return Res;
}

Pile& Lastop::operation(const Pile& P)
{
    Pile &Res = *(new Pile(P));

    return Res;
}

Pile& Lastargs::operation(const Pile& P)
{
    Pile &Res = *(new Pile(P));

    return Res;
}

Pile& Redo::operation(const Pile& P)
{
    Pile &Res = *(new Pile(P));

    return Res;
}
/*Pile& OperateurNumerique::operation(const Pile &P)
{
    Pile &Res = * (new Pile(P));
    Litteral_calculable **L_tab = new Litteral_calculable*[arite];
    int taille_P = P.getTaille();
    for(int i= taille_P - 1;i >= taille_P - arite;i--) // On parcours la pile � l'envers
    {
        try
        {
            L_tab[taille_P - 1 - i] = dynamic_cast<Litteral_calculable*> ( &(Res.pop()) );
        }
        catch (bad_cast& bc)
        {
            throw(ExceptionOperateur("Un des litt�ral n'est pas calculable", litteralNonCalculable));
        }
    }
    Litteral_calculable &L_Res = calcul(L_tab);
    Res.push(L_Res);
    return Res;
} */
void Eval::appliquer(Computer& c)
{
    Litteral& L_a_evaluer = c.pop();
    Litteral* Res = L_a_evaluer.eval(c);
    if(Res != 0)
        c.push(*Res);
}
Pile& Sto::operation(const Pile &P)
{
    Pile &Res = * (new Pile(P));
        Litteral &L1 = (Res.pop()) ;
        Litteral &L2 = ( (Res.pop()) );
        ostringstream os;
        os << L1;
        cout << L1.toStr();
        if(os.str()[0] == '[')
            getAnalyseur()->getAtomes().ajouterAtome(os.str(),L2);
        else
            getAnalyseur()->getAtomes().ajouterAtome(L1.toStr(),L2);
        return Res;
}
