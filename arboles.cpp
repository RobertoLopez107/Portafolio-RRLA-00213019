Arbol 1:
  Nodos:
    1)Ra�z:  A
    2)Ramas: B, C, D, E
    3)Hojas: G, H, I, F
  
  Niveles de los nodos:
    1)Nivel 0: A
    2)Nivel 1: B, C
    3)Nivel 2: D, E, F
    4)Nivel 3: G, H, I
    
  Profundidad: Nivel 3
  
  Peso: 9 nodos
  
  Sub-�rbol: 
    Raiz: E                        (E)
    Hojas: H, I                   /   \ 
                                (H)   (I)
                                
  El �rbol es estricto: NO, porque a de le falta un hijo para que fuera un �rbol estricto.
  
  El �rbol es completo: NO, porque no es estricto y las hojas no todas son del mismo nivel.
  
  Recorridos:
    1)Pre-orden:  A, B, D, G, C, E, H, I, F
    2)Post-orden: G, D, B, H, I, E, F, C, A
    3)In-orden:   D, G, B, A, H, E, I, C, F
    
Arbol 2: 
  Nodos:
    1)Ra�z:  A
    2)Ramas: B, C, D, E, F, H
    3)Hojas: I, J, G, K, L
    
  Nivel de los nodos:
    1)Nivel 0:  A
    2)Nivel 1:  B
    3)Nivel 2:  C, D
    4)Nivel 3:  E, F, G, H
    5)Nivel 4:  i, J, K, L
        
  Profundidad: Nivel 4
  
  Peso: 12 nodos
  
  Sub-�rbol:                                    (D)
    Ra�z:   D                                  /   \
    Ramas:  H                                (G)   (H)
    Hojas:  G, K, L                               /   \
                                                (K)   (L)   
                                                
  El �rbol es estricto: NO, porque no todos los nodos tienen 0 � 2 hijos
  
  El �rbol es completo: NO, porque no es estricto y sus hojas no terminan en el mismo nivel
  
  Recorridos:
    1)Pre-orden:  A, B, C, E, I, F, J, D, G, H, F, L
    2)Post-orden: I, E, J, E, C, G, F, L, H, D, B, A 
    3)In-orden:   E, I, C, F, J, B, C, D, K, H, L, A