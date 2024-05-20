#include "commons.cpp"
#include "listaDuplamenteEncadeada.cpp"
#include "arvoreBinaria.cpp"

int main() {
  DLinkedList<BinTreeNode>* lista = new DLinkedList<BinTreeNode>;
  BinTree tree;
  string frase = "rato roeu a roupa do rei de roma";

  for (int i = 0; i < frase.length(); i++) { 
    char c = frase[i];
    if(lista->findCharacter(c)){//Se existir o char na lista.
      lista->updateFreq(c);//Atualiza a frequência.
    }
    else{//Se não adiciona o char na lista.
      BinTreeNode* n = new BinTreeNode;
      n->character = c;
      n->freq = 1;
      lista->insert(n);
    }
  }
  cout << frase << "\n";
  lista->ordenarLista();
  lista->show();
  cout << "\n";
  cout << "\n";

  while(lista->length>1){//Da merge nos Nodes de menor frequência.
    BinTreeNode* v1 = new BinTreeNode;
    BinTreeNode* v2 = new BinTreeNode;
    BinTreeNode* newNode = new BinTreeNode;
    lista->retirar(*v1);
    lista->retirar(*v2);
    newNode->freq = v1->freq + v2->freq;
    newNode->left = v1;
    newNode->right = v2;
    lista->insertInOrder(newNode);
    lista->show();
    cout << "\n";
    tree.root = newNode;
  }
  cout << "\n";

  tree.wholeWalk(tree.root);
  system("pause"); //Não tirar, to compilando pelo VS Code.
}
