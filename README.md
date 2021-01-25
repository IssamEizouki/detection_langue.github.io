**Automatic Language Detection**
--------------------------------

**Introduction**

Detecting the language of a given paragraph, using one of the two following data structures :
1. Trie : (digital tree ) or (prefix tree).
2. DAWG : (directed acyclic word graph).
_________________________

**A Trie structure :**

Every Node has: 

                - a boolean which serves to know if the letters from the root to the actual node is a word or not.(if this node representes the final letter of a word).
                
                - a list(of nodes), of 26 cases for the letters from a to z.

                For each case, it points on NULL if there is not an edge to this letter. and points on a node representing this letter if there is an edge.
_________________________
**DAWG structure :**

In DAWG structure, i used 2 recursive structures that represente a DAWG:
1. `Sommet` representing the graph nodes .
2. `Arete`  representing Arrows that point in one direction.

I also used some structures needed in this implementation:

1. `Hashmap` to stock the informations, it serves in the minimization part .
2. `Stack` serves in both, the insertion part and the minimization part .

_________________________

