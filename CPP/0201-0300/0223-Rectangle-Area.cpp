    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (A >= G || B >= H || C <= E || D <= F) {
            return (C-A) * (D-B) + (G-E) * (H-F);
        } else {
            return (C-A) * (D-B) + (G-E) * (H-F) - min(min(min(C-A, G-E), abs(E-C)), abs(G-A)) * min(min(min(D-B, H-F), abs(H-B)), abs(F-D));
        }
    }
