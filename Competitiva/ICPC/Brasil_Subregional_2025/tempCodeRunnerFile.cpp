  forn(i, t){
                if(cont == f){
                    candidatos.push_back(text[i]);
                    cont = f - aux;
                }
                if(text[i] == query[cont]) cont++; 
                else cont = f - aux;
            }