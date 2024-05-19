#include "commons.cpp"
#include "listaDuplamenteEncadeada.cpp"
#include "arvoreBinaria.cpp"

int main() {
  DLinkedList<BinTreeNode>* lista = new DLinkedList<BinTreeNode>;
  string frase = "rato roeu a roupa do rei de roma";

  for (int i = 0; i < frase.length(); i++) { 
    char c = frase[i];
    if(lista->findCharacter(c)){
      lista->updateFreq(c);
    }
    else{
      BinTreeNode* n = new BinTreeNode;
      n->character = c;
      n->freq = 1;
      lista->insert(n);
    }
  } 
  lista->ordenarLista();
  lista->show();
}
