#include "Player.hh"
#include <vector>
#include <iostream>
#include <queue>
#include <list>
using namespace std;



/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Verstappen


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  /**
   * Types and attributes for your player can be defined here.
   */

  /**
   * Play method, invoked once per each round.
   */
   typedef vector <char>VC;
   typedef vector <VC>VVC;

   typedef vector <bool>VB;
   typedef vector <VB>VVB;

   typedef vector<int> VI;
   typedef vector<VI>  VVI;



   Pos ciutat_nord_esquerra;
   Pos ciutat_nord_dreta;
   Pos ciutat_sud_esquerra;
   Pos ciutat_sud_dreta;

   struct Components {
       int id_base;
       int id_aprop;
   };

   vector<Components> quadrants;

   int bfs_lloc(Pos posicio, int tipus) {
       int i = posicio.i;
       int j = posicio.j;
       VVB vis(70, VB(70, false));

       queue <pair <pair <int, int>, int> > q;
       int v;
       q.push(make_pair(make_pair(i, j), v));

       	int x, y;
        bool first = true;

       	while (!q.empty()) {
       		x = (q.front().first).first;
       		y = (q.front().first).second;
       		v = q.front().second;
       		q.pop();
            Pos paux;
            paux.i = x;
            paux.j = y;
       	    if (pos_ok(paux) and cell(paux).type == tipus) return v;
       		else if (!vis[x][y]) {
       			vis[x][y] = true;
                Pos p3 = paux;
                p3.j = y-1;
       			if (pos_ok(p3) and cell(p3).type != WALL) {
       				if (first) v = 3;
       				q.push(make_pair(make_pair(x, y-1), v));
       			}
                Pos p1 = paux;
                p1.j = y+1;
       			if (pos_ok(p1) and cell(p1).type != WALL) {
       				if (first) v = 1;
       				q.push(make_pair(make_pair(x, y+1), v));
       			}
                Pos p0 = paux;
                p0.i = x+1;
       			if (pos_ok(p0) and cell(p0).type != WALL) {
       				if (first) v = 0;
       				q.push(make_pair(make_pair(x+1, y), v));
       			}
                Pos p2 = paux;
                p0.i = x-1;
       			if (pos_ok(p2) and cell(p2).type != WALL) {
       				if (first) v = 2;
       				q.push(make_pair(make_pair(x-1, y),v));

       			}
       		}
            first = false;
       	}
    }
    int bfs_anar_mascareta(Pos posicio) {
        int i = posicio.i;
        int j = posicio.j;
        VVB vis(70, VB(70, false));

        queue <pair <pair <int, int>, int> > q;
        int v;
        q.push(make_pair(make_pair(i, j), v));

        	int x, y;
         bool first = true;

        	while (!q.empty()) {
        		x = (q.front().first).first;
        		y = (q.front().first).second;
        		v = q.front().second;
        		q.pop();
             Pos paux;
             paux.i = x;
             paux.j = y;
        	    if (pos_ok(paux) and cell(paux).mask) return v;
        		else if (!vis[x][y]) {
        			vis[x][y] = true;
                 Pos p3 = paux;
                 p3.j = y-1;
        			if (pos_ok(p3) and cell(p3).type != WALL) {
        				if (first) v = 3;
        				q.push(make_pair(make_pair(x, y-1), v));
        			}
                 Pos p1 = paux;
                 p1.j = y+1;
        			if (pos_ok(p1) and cell(p1).type != WALL) {
        				if (first) v = 1;
        				q.push(make_pair(make_pair(x, y+1), v));
        			}
                 Pos p0 = paux;
                 p0.i = x+1;
        			if (pos_ok(p0) and cell(p0).type != WALL) {
        				if (first) v = 0;
        				q.push(make_pair(make_pair(x+1, y), v));
        			}
                 Pos p2 = paux;
                 p0.i = x-1;
        			if (pos_ok(p2) and cell(p2).type != WALL) {
        				if (first) v = 2;
        				q.push(make_pair(make_pair(x-1, y),v));

        			}
        		}
             first = false;
        	}
     }
     int juntar(Pos posicio) {
         int i = posicio.i;
         int j = posicio.j;
         VVB vis(70, VB(70, false));

         queue <pair <pair <int, int>, int> > q;
         int v;
         q.push(make_pair(make_pair(i, j), v));

           int x, y;
          bool first = true;

           while (!q.empty()) {
               x = (q.front().first).first;
               y = (q.front().first).second;
               v = q.front().second;
               q.pop();
              Pos paux;
              paux.i = x;
              paux.j = y;
               if (cell(paux).unit_id != -1 and pertany_ales_meves(cell(paux).unit_id)) return v;
               else if (!vis[x][y]) {
                   vis[x][y] = true;
                  Pos p3 = paux;
                  p3.j = y-1;
                   if (pos_ok(p3) and cell(p3).type == CITY) {
                       if (first) v = 3;
                       q.push(make_pair(make_pair(x, y-1), v));
                   }
                  Pos p1 = paux;
                  p1.j = y+1;
                   if (pos_ok(p1) and cell(p1).type  == CITY) {
                       if (first) v = 1;
                       q.push(make_pair(make_pair(x, y+1), v));
                   }
                  Pos p0 = paux;
                  p0.i = x+1;
                   if (pos_ok(p0) and cell(p0).type == CITY) {
                       if (first) v = 0;
                       q.push(make_pair(make_pair(x+1, y), v));
                   }
                  Pos p2 = paux;
                  p0.i = x-1;
                   if (pos_ok(p2) and cell(p2).type  == CITY) {
                       if (first) v = 2;
                       q.push(make_pair(make_pair(x-1, y),v));

                   }
               }
              first = false;
           }
      }
     int buscar_matar(Pos posicio, int id_ciu) {
         int i = posicio.i;
         int j = posicio.j;
         VVB vis(70, VB(70, false));

         queue <pair <pair <int, int>, int> > q;
         int v;
         q.push(make_pair(make_pair(i, j), v));

         	int x, y;
          bool first = true;

         	while (!q.empty()) {
         		x = (q.front().first).first;
         		y = (q.front().first).second;
         		v = q.front().second;
         		q.pop();
              Pos paux;
              paux.i = x;
              paux.j = y;
         	    if (cell(paux).type == CITY and cell(posicio).city_id == id_ciu and cell(paux).unit_id != -1 and not pertany_ales_meves(cell(paux).unit_id)) return v;
         		else if (!vis[x][y]) {
         			vis[x][y] = true;
                  Pos p3 = paux;
                  p3.j = y-1;
         			if (pos_ok(p3) and cell(p3).type == CITY) {
         				if (first) v = 3;
         				q.push(make_pair(make_pair(x, y-1), v));
         			}
                  Pos p1 = paux;
                  p1.j = y+1;
         			if (pos_ok(p1) and cell(p1).type  == CITY) {
         				if (first) v = 1;
         				q.push(make_pair(make_pair(x, y+1), v));
         			}
                  Pos p0 = paux;
                  p0.i = x+1;
         			if (pos_ok(p0) and cell(p0).type == CITY) {
         				if (first) v = 0;
         				q.push(make_pair(make_pair(x+1, y), v));
         			}
                  Pos p2 = paux;
                  p0.i = x-1;
         			if (pos_ok(p2) and cell(p2).type  == CITY) {
         				if (first) v = 2;
         				q.push(make_pair(make_pair(x-1, y),v));

         			}
         		}
              first = false;
         	}
      }
      int buscar_matar_path(Pos posicio, int id_p) {
          int i = posicio.i;
          int j = posicio.j;
          VVB vis(70, VB(70, false));

          queue <pair <pair <int, int>, int> > q;
          int v;
          q.push(make_pair(make_pair(i, j), v));

          	int x, y;
           bool first = true;

          	while (!q.empty()) {
          		x = (q.front().first).first;
          		y = (q.front().first).second;
          		v = q.front().second;
          		q.pop();
               Pos paux;
               paux.i = x;
               paux.j = y;
          	    if (cell(paux).type == PATH and cell(posicio).path_id == id_p and cell(paux).unit_id != -1 and not pertany_ales_meves(cell(paux).unit_id)) return v;
          		else if (!vis[x][y]) {
          			vis[x][y] = true;
                   Pos p3 = paux;
                   p3.j = y-1;
          			if (pos_ok(p3) and cell(p3).type == PATH) {
          				if (first) v = 3;
          				q.push(make_pair(make_pair(x, y-1), v));
          			}
                   Pos p1 = paux;
                   p1.j = y+1;
          			if (pos_ok(p1) and cell(p1).type == PATH) {
          				if (first) v = 1;
          				q.push(make_pair(make_pair(x, y+1), v));
          			}
                   Pos p0 = paux;
                   p0.i = x+1;
          			if (pos_ok(p0) and cell(p0).type == PATH) {
          				if (first) v = 0;
          				q.push(make_pair(make_pair(x+1, y), v));
          			}
                   Pos p2 = paux;
                   p0.i = x-1;
          			if (pos_ok(p2) and cell(p2).type == PATH) {
          				if (first) v = 2;
          				q.push(make_pair(make_pair(x-1, y),v));

          			}
          		}
               first = false;
          	}
       }

     int bfs_distancia_mascareta(Pos posicio) {
         int i = posicio.i;
         int j = posicio.j;
         VVB vis(70, VB(70, false));

         queue <pair <pair <int, int>, int> > q;
         int d = 0;
         q.push(make_pair(make_pair(i, j), d));

            int x, y;

            while (!q.empty()) {
                x = (q.front().first).first;
                y = (q.front().first).second;
                d = q.front().second;
                q.pop();
              Pos paux;
              paux.i = x;
              paux.j = y;
                if (pos_ok(paux) and cell(paux).mask) return d;
                else if (d > 3) return -1;
                else if (!vis[x][y]) {
                    vis[x][y] = true;
                  Pos p3 = paux;
                  p3.j = y-1;
                    if (pos_ok(p3) and cell(p3).type != WALL) {
                        q.push(make_pair(make_pair(x, y-1), d+1));
                    }
                  Pos p1 = paux;
                  p1.j = y+1;
                    if (pos_ok(p1) and cell(p1).type != WALL) {
                        q.push(make_pair(make_pair(x, y+1), d+1));
                    }
                  Pos p0 = paux;
                  p0.i = x+1;
                    if (pos_ok(p0) and cell(p0).type != WALL) {
                        q.push(make_pair(make_pair(x+1, y), d+1));
                    }
                  Pos p2 = paux;
                  p0.i = x-1;
                    if (pos_ok(p2) and cell(p2).type != WALL) {
                        q.push(make_pair(make_pair(x-1, y),d+1));

                    }
                }
                else return -1;
            }
      }

    int bfs_lloc_no_conquerit(Pos posicio) {
        int i = posicio.i;
        int j = posicio.j;
        VVB vis(70, VB(70, false));

        queue <pair <pair <int, int>, int> > q;
        int v;
        q.push(make_pair(make_pair(i, j), v));

        	int x, y;
         bool first = true;

        	while (!q.empty()) {
        		x = (q.front().first).first;
        		y = (q.front().first).second;
        		v = q.front().second;
        		q.pop();
             Pos paux;
             paux.i = x;
             paux.j = y;
        	    if (pos_ok(paux) and
                    (cell(paux).type == CITY and city_owner(cell(paux).city_id) != me())
                    or (cell(paux).type == PATH and path_owner(cell(paux).path_id) != me())) return v;
        		else if (!vis[x][y]) {
        			vis[x][y] = true;
                 Pos p3 = paux;
                 p3.j = y-1;
        			if (pos_ok(p3) and cell(p3).type != WALL) {
        				if (first) v = 3;
        				q.push(make_pair(make_pair(x, y-1), v));
        			}
                 Pos p1 = paux;
                 p1.j = y+1;
        			if (pos_ok(p1) and cell(p1).type != WALL) {
        				if (first) v = 1;
        				q.push(make_pair(make_pair(x, y+1), v));
        			}
                 Pos p0 = paux;
                 p0.i = x+1;
        			if (pos_ok(p0) and cell(p0).type != WALL) {
        				if (first) v = 0;
        				q.push(make_pair(make_pair(x+1, y), v));
        			}
                 Pos p2 = paux;
                 p0.i = x-1;
        			if (pos_ok(p2) and cell(p2).type != WALL) {
        				if (first) v = 2;
        				q.push(make_pair(make_pair(x-1, y),v));

        			}
        		}
             first = false;
        	}
     }
     int bfs_lloc_no_conquerit_buit(Pos posicio) {
         int i = posicio.i;
         int j = posicio.j;
         VVB vis(70, VB(70, false));

         queue <pair <pair <int, int>, pair <int, int>> > q;
         int v;
         int d = 0;
         q.push(make_pair(make_pair(i, j), make_pair(v, d)));

         	int x, y;
          bool first = true;

         	while (!q.empty()) {
         		x = (q.front().first).first;
         		y = (q.front().first).second;
         		v = (q.front().second).first;
                d = (q.front().second).second;
         		q.pop();
              Pos paux;
              paux.i = x;
              paux.j = y;
         	    if (pos_ok(paux) and
                     (cell(paux).type == CITY and city_owner(cell(paux).city_id) != me()
                     and not hi_ha_rivals(cell(paux).city_id))
                     or (cell(paux).type == PATH and path_owner(cell(paux).path_id) != me()
                 and not hi_ha_rivals_path(cell(paux).path_id))) return v;
                 else if (d > 39) return -1;
         		else if (!vis[x][y]) {
         			vis[x][y] = true;
                  Pos p3 = paux;
                  p3.j = y-1;
         			if (pos_ok(p3) and cell(p3).type != WALL) {
         				if (first) v = 3;
         				q.push(make_pair(make_pair(x, y-1), make_pair(v,d+1)));
         			}
                  Pos p1 = paux;
                  p1.j = y+1;
         			if (pos_ok(p1) and cell(p1).type != WALL) {
         				if (first) v = 1;
         				q.push(make_pair(make_pair(x, y+1), make_pair(v,d+1)));
         			}
                  Pos p0 = paux;
                  p0.i = x+1;
         			if (pos_ok(p0) and cell(p0).type != WALL) {
         				if (first) v = 0;
         				q.push(make_pair(make_pair(x+1, y), make_pair(v,d+1)));
         			}
                  Pos p2 = paux;
                  p0.i = x-1;
         			if (pos_ok(p2) and cell(p2).type != WALL) {
         				if (first) v = 2;
         				q.push(make_pair(make_pair(x-1, y),make_pair(v,d+1)));

         			}
         		}
              first = false;
         	}
      }

    int bfs_retornar_id_ciutat(int id_ciu) {
        Pos posicio =  city(id_ciu)[0];
        int i = posicio.i;
        int j = posicio.j;
        VVB vis(70, VB(70, false));

        queue <pair <pair <int, int>, int> > q;
        int v;
        q.push(make_pair(make_pair(i, j), v));

        	int x, y;
         bool first = true;

        	while (!q.empty()) {
        		x = (q.front().first).first;
        		y = (q.front().first).second;
        		v = q.front().second;
        		q.pop();
             Pos paux;
             paux.i = x;
             paux.j = y;
        	    if (pos_ok(paux) and cell(paux).type == CITY and cell(paux).city_id != id_ciu)
                    return cell(paux).city_id;
        		else if (!vis[x][y]) {
        			vis[x][y] = true;
                 Pos p3 = paux;
                 p3.j = y-1;
        			if (pos_ok(p3) and cell(p3).type != WALL) {
        				if (first) v = 3;
        				q.push(make_pair(make_pair(x, y-1), v));
        			}
                 Pos p1 = paux;
                 p1.j = y+1;
        			if (pos_ok(p1) and cell(p1).type != WALL) {
        				if (first) v = 1;
        				q.push(make_pair(make_pair(x, y+1), v));
        			}
                 Pos p0 = paux;
                 p0.i = x+1;
        			if (pos_ok(p0) and cell(p0).type != WALL) {
        				if (first) v = 0;
        				q.push(make_pair(make_pair(x+1, y), v));
        			}
                 Pos p2 = paux;
                 p0.i = x-1;
        			if (pos_ok(p2) and cell(p2).type != WALL) {
        				if (first) v = 2;
        				q.push(make_pair(make_pair(x-1, y),v));

        			}
        		}
             first = false;
        	}
     }


    int bfs_id(Pos posicio, int id_ciu) {
        int i = posicio.i;
        int j = posicio.j;
        VVB vis(70, VB(70, false));

        queue <pair <pair <int, int>, int> > q;
        int v;
        q.push(make_pair(make_pair(i, j), v));

        	int x, y;
         bool first = true;

        	while (!q.empty()) {
        		x = (q.front().first).first;
        		y = (q.front().first).second;
        		v = q.front().second;
        		q.pop();
             Pos paux;
             paux.i = x;
             paux.j = y;
        	    if (pos_ok(paux) and cell(paux).type == CITY and cell(paux).city_id == id_ciu) return v;
        		else if (!vis[x][y]) {
        			vis[x][y] = true;
                 Pos p3 = paux;
                 p3.j = y-1;
        			if (pos_ok(p3) and cell(p3).type != WALL) {
        				if (first) v = 3;
        				q.push(make_pair(make_pair(x, y-1), v));
        			}
                 Pos p1 = paux;
                 p1.j = y+1;
        			if (pos_ok(p1) and cell(p1).type != WALL) {
        				if (first) v = 1;
        				q.push(make_pair(make_pair(x, y+1), v));
        			}
                 Pos p0 = paux;
                 p0.i = x+1;
        			if (pos_ok(p0) and cell(p0).type != WALL) {
        				if (first) v = 0;
        				q.push(make_pair(make_pair(x+1, y), v));
        			}
                 Pos p2 = paux;
                 p0.i = x-1;
        			if (pos_ok(p2) and cell(p2).type != WALL) {
        				if (first) v = 2;
        				q.push(make_pair(make_pair(x-1, y),v));

        			}
        		}
             first = false;
        	}
     }

     int bfs_not_id(Pos posicio, int id_ciu) {
         int i = posicio.i;
         int j = posicio.j;
         VVB vis(70, VB(70, false));

         queue <pair <pair <int, int>, int> > q;
         int v;
         q.push(make_pair(make_pair(i, j), v));

         	int x, y;
          bool first = true;

         	while (!q.empty()) {
         		x = (q.front().first).first;
         		y = (q.front().first).second;
         		v = q.front().second;
         		q.pop();
              Pos paux;
              paux.i = x;
              paux.j = y;
         	    if (pos_ok(paux) and cell(paux).type == CITY and cell(paux).city_id != id_ciu) return v;
         		else if (!vis[x][y]) {
         			vis[x][y] = true;
                  Pos p3 = paux;
                  p3.j = y-1;
         			if (pos_ok(p3) and cell(p3).type != WALL) {
         				if (first) v = 3;
         				q.push(make_pair(make_pair(x, y-1), v));
         			}
                  Pos p1 = paux;
                  p1.j = y+1;
         			if (pos_ok(p1) and cell(p1).type != WALL) {
         				if (first) v = 1;
         				q.push(make_pair(make_pair(x, y+1), v));
         			}
                  Pos p0 = paux;
                  p0.i = x+1;
         			if (pos_ok(p0) and cell(p0).type != WALL) {
         				if (first) v = 0;
         				q.push(make_pair(make_pair(x+1, y), v));
         			}
                  Pos p2 = paux;
                  p0.i = x-1;
         			if (pos_ok(p2) and cell(p2).type != WALL) {
         				if (first) v = 2;
         				q.push(make_pair(make_pair(x-1, y),v));

         			}
         		}
              first = false;
         	}
      }





   int esquivar(Pos proxima_pos, Pos posicio) {
       int r;
       if (proxima_pos.i == posicio.i) {
           r = random(0,1);
           if (r == 1) ++r; //nort
       }
       else {
           r = random(1,3);
           if (r == 2) --r; //dreta
       }
       return r;

   }

   void ronda_inicial() {
       VI vector_unitats = my_units(me());//vector amb ids de les unitats
       int n = vector_unitats.size();
       for(int i = 0; i < n; ++i) {
           int id = vector_unitats[i];
           if (unit(id).pos.i == 1) move(id,Dir(0));
           else if (unit(id).pos.j == 1) move(id,Dir(1));
           else if (unit(id).pos.i == 68) move(id,Dir(2));
           else if (unit(id).pos.j == 68) move(id,Dir(3));

       }
   }

   Pos proxima_p(Pos posicio, int proxim_mov) {
       Pos proxima_pos = posicio;
       if (proxim_mov == 0) ++proxima_pos.i;
       else if (proxim_mov == 1) ++proxima_pos.j;
       else if (proxim_mov == 2) --proxima_pos.i;
       else if (proxim_mov == 3) --proxima_pos.j;
       return proxima_pos;
   }

   bool pertany_ales_meves(int u_id) {
       VI vector_unitats = my_units(me());//vector amb ids de les unitats
       int n = vector_unitats.size();
       for(int i = 0; i < n; ++i) {
           if (vector_unitats[i] == u_id) return true;
       }
       return false;
   }

    void identificar_mapa() {
        int nombre_ciutats = nb_cities ();
        int max_nord_esq = 0;
        int max_nord_dreta = 0;
        int max_sud_esq = 0;
        int max_sud_dreta = 0;
        for(int i = 0; i < nombre_ciutats; ++i) {
            int mida = city(i).size();
            if (mida > max_nord_esq and city(i)[0].i <= 34 and city(i)[0].j <= 34 ) {
                max_nord_esq = mida;
                ciutat_nord_esquerra.i = city(i)[0].i;
                ciutat_nord_esquerra.j = city(i)[0].j;
                quadrants[0].id_base = i;
            }
            else if (mida > max_nord_dreta and city(i)[0].i <= 34 and city(i)[0].j > 34 ) {
                max_nord_dreta = mida;
                ciutat_nord_dreta.i = city(i)[0].i;
                ciutat_nord_dreta.j = city(i)[0].j;
                quadrants[1].id_base = i;
            }
            else if (mida > max_sud_esq and city(i)[0].i > 34 and city(i)[0].j <= 34 ) {
                max_sud_esq = mida;
                ciutat_sud_esquerra.i = city(i)[0].i;
                ciutat_sud_esquerra.j = city(i)[0].j;
                quadrants[2].id_base = i;
            }
            else if (mida > max_sud_dreta and city(i)[0].i > 34 and city(i)[0].j > 34 ) {
                max_sud_dreta = mida;
                ciutat_sud_dreta.i = city(i)[0].i;
                ciutat_sud_dreta.j = city(i)[0].j;
                quadrants[3].id_base = i;
            }
        }
        for (int i = 0; i < 4; ++i)
            quadrants[i].id_aprop = bfs_retornar_id_ciutat(quadrants[i].id_base);

    }
    int encaminar(Pos pos, int component) {
        if ( component == 0) {
            int i = pos.i;
            int j = pos.j;
            if (i <= 34 and j <= 34) return quadrants[0].id_base;
            else if (i <= 34 and j > 34) return quadrants[1].id_base;
            else if (i > 34 and j <= 34) return quadrants[2].id_base;
            else return quadrants[3].id_base;
        }
        else if ( component == 1) {
            int i = pos.i;
            int j = pos.j;
            if (i <= 34 and j <= 34) return quadrants[0].id_aprop;
            else if (i <= 34 and j > 34) return quadrants[1].id_aprop;
            else if (i > 34 and j <= 34) return quadrants[2].id_aprop;
            else return quadrants[3].id_aprop;
        }

    }

    int num_q(Pos pos) {
        int i = pos.i;
        int j = pos.j;
        if (i <= 34 and j <= 34) return 0;
        else if (i <= 34 and j > 34) return 1;
        else if (i > 34 and j <= 34) return 2;
        else return 3;
    }

    int possible_enemic(Pos posicio){
        Pos proxima_pos0 = posicio;
        ++proxima_pos0.i;
        int u_id0 = cell(proxima_pos0).unit_id;
        if (pos_ok(proxima_pos0) and u_id0 != -1 and not pertany_ales_meves(u_id0))
            return 0;

        Pos proxima_pos1 = posicio;
        ++proxima_pos1.j;
        int u_id1 = cell(proxima_pos1).unit_id;
        if (pos_ok(proxima_pos1) and u_id1 != -1 and not pertany_ales_meves(u_id1))
            return 1;

        Pos proxima_pos2 = posicio;
        --proxima_pos2.i;
        int u_id2 = cell(proxima_pos2).unit_id;
        if (pos_ok(proxima_pos2) and u_id2 != -1 and not pertany_ales_meves(u_id2))
            return 2;

        Pos proxima_pos3 = posicio;
        --proxima_pos3.j;
        int u_id3 = cell(proxima_pos3).unit_id;
        if (pos_ok(proxima_pos3) and u_id3 != -1 and not pertany_ales_meves(u_id3))
            return 3;
        return -1;
    }
    bool junts(Pos posicio){
        Pos proxima_pos0 = posicio;
        ++proxima_pos0.i;
        int u_id0 = cell(proxima_pos0).unit_id;
        if (pos_ok(proxima_pos0) and u_id0 != -1 and pertany_ales_meves(u_id0))
            return true;

        Pos proxima_pos1 = posicio;
        ++proxima_pos1.j;
        int u_id1 = cell(proxima_pos1).unit_id;
        if (pos_ok(proxima_pos1) and u_id1 != -1 and pertany_ales_meves(u_id1))
            return true;

        Pos proxima_pos2 = posicio;
        --proxima_pos2.i;
        int u_id2 = cell(proxima_pos2).unit_id;
        if (pos_ok(proxima_pos2) and u_id2 != -1 and pertany_ales_meves(u_id2))
            return true;

        Pos proxima_pos3 = posicio;
        --proxima_pos3.j;
        int u_id3 = cell(proxima_pos3).unit_id;
        if (pos_ok(proxima_pos3) and u_id3 != -1 and pertany_ales_meves(u_id3))
            return true;
        return false;
    }
    int possible_path(Pos posicio){
        Pos proxima_pos0 = posicio;
        ++proxima_pos0.i;

        if (pos_ok(proxima_pos0) and cell(proxima_pos0).type == PATH
            and path_owner(cell(proxima_pos0).path_id) != me())
                return 0;

        Pos proxima_pos1 = posicio;
        ++proxima_pos1.j;
        int u_id1 = cell(proxima_pos1).unit_id;
        if (pos_ok(proxima_pos1) and cell(proxima_pos1).type == PATH
            and path_owner(cell(proxima_pos1).path_id) != me())
                return 1;

        Pos proxima_pos2 = posicio;
        --proxima_pos2.i;
        int u_id2 = cell(proxima_pos2).unit_id;
        if (pos_ok(proxima_pos2) and cell(proxima_pos2).type == PATH
            and path_owner(cell(proxima_pos2).path_id) != me())
                return 2;

        Pos proxima_pos3 = posicio;
        --proxima_pos3.j;
        int u_id3 = cell(proxima_pos3).unit_id;
        if (pos_ok(proxima_pos3) and cell(proxima_pos3).type == PATH
            and path_owner(cell(proxima_pos3).path_id) != me())
                return 3;
        return -1;
    }

    int mou_random(Pos posicio, int id_ciutat_base) {
        Pos p2 = posicio;
        int r = random(0,3);
        if (r == 0) {
            ++p2.i;
            if (pos_ok(p2) and cell(p2).type == CITY and cell(p2).city_id == id_ciutat_base) return 0;
            else return mou_random(posicio, id_ciutat_base);
        }
        else if (r == 1) {
            ++p2.j;
            if (pos_ok(p2) and cell(p2).type == CITY and cell(p2).city_id == id_ciutat_base) return 1;
            else return mou_random(posicio, id_ciutat_base);
        }
        else if (r == 2) {
            --p2.i;
            if (pos_ok(p2) and cell(p2).type == CITY and cell(p2).city_id == id_ciutat_base) return 2;
            else return mou_random(posicio, id_ciutat_base);
        }
        else  {
            --p2.j;
            if (pos_ok(p2) and cell(p2).type == CITY and cell(p2).city_id == id_ciutat_base) return 3;
            else return mou_random(posicio, id_ciutat_base);
        }
    }

    int mou_random_path(Pos posicio, int id_ciutat_base) {
        Pos p2 = posicio;
        int r = random(0,3);
        if (r == 0) {
            ++p2.i;
            if (pos_ok(p2) and cell(p2).type == PATH and cell(p2).path_id == id_ciutat_base) return 0;
            else return mou_random_path(posicio, id_ciutat_base);
        }
        else if (r == 1) {
            ++p2.j;
            if (pos_ok(p2) and cell(p2).type == PATH and cell(p2).path_id == id_ciutat_base) return 1;
            else return mou_random_path(posicio, id_ciutat_base);
        }
        else if (r == 2) {
            --p2.i;
            if (pos_ok(p2) and cell(p2).type == PATH and cell(p2).path_id == id_ciutat_base) return 2;
            else return mou_random_path(posicio, id_ciutat_base);
        }
        else  {
            --p2.j;
            if (pos_ok(p2) and cell(p2).type == PATH and cell(p2).path_id == id_ciutat_base) return 3;
            else return mou_random_path(posicio, id_ciutat_base);
        }
    }

    bool es_toca_ciu(Pos posicio, int id_ciu) {
        Pos proxima_pos0 = posicio;
        ++proxima_pos0.i;
        if (pos_ok(proxima_pos0) and cell(proxima_pos0).type == CITY and cell(proxima_pos0).city_id == id_ciu) return true;

        Pos proxima_pos1 = posicio;
        ++proxima_pos1.i;
        if (pos_ok(proxima_pos1) and cell(proxima_pos1).type == CITY and cell(proxima_pos1).city_id == id_ciu) return true;

        Pos proxima_pos2 = posicio;
        ++proxima_pos2.i;
        if (pos_ok(proxima_pos2) and cell(proxima_pos2).type == CITY and cell(proxima_pos2).city_id == id_ciu) return true;

        Pos proxima_pos3 = posicio;
        ++proxima_pos3.i;
        if (pos_ok(proxima_pos3) and cell(proxima_pos3).type == CITY and cell(proxima_pos3).city_id == id_ciu) return true;

        return false;

    }

    bool sol(int id, int id_ciu) {
        VI vector_unitats = my_units(me());//vector amb ids de les unitats
        int n = vector_unitats.size();
        for (int i = 0; i < n; ++i) {
            Pos posicio = unit(vector_unitats[i]).pos;
            if (vector_unitats[i] != id and
                cell(posicio).type == CITY and cell(posicio).city_id == id_ciu) return false;

        }

        return true;

    }
    bool hi_ha_rivals(int id_ciu) {
        City ciu = city(id_ciu);
        for(int i = 0; i < ciu.size(); ++i) {
            int id_u = cell(ciu[i]).unit_id;
            if (id_u != -1 and not pertany_ales_meves(id_u)) return true;
        }
        return false;
    }
    bool hi_ha_rivals_path(int id_p) {
        Path p = path(id_p);
        for(int i = 0; i < p.second.size(); ++i) {
            int id_u = cell(p.second[i]).unit_id;
            if (id_u != -1 and not pertany_ales_meves(id_u)) return true;
        }
        return false;
    }

    int quantitat_u(int id_c) {
        VI vector_unitats = my_units(me());//vector amb ids de les unitats
        int n = vector_unitats.size();
        int c = 0;
        for(int i = 0; i < n; ++i) {
            Pos posicio = unit(vector_unitats[i]).pos;
            if (cell(posicio).city_id == id_c) ++c;
        }
        return c;
    }

    void move_units() {
        VI vector_unitats = my_units(me());//vector amb ids de les unitats
        int n = vector_unitats.size();
        for (int i = 0; i < n; ++i) {
           int id = vector_unitats[i];
           Pos posicio = unit(id).pos;
           int proxim_mov;
           int ciutat_base = quadrants[num_q(posicio)].id_base;
         if (possible_enemic(posicio) != -1) proxim_mov = possible_enemic(posicio);



         else if (id %2 == 0) {
             if ((cell(posicio).type == CITY and cell(posicio).city_id == ciutat_base) or
                 ((cell(posicio).type == PATH) and
                 (path(cell(posicio).path_id).first.first == ciutat_base or
                 path(cell(posicio).path_id).first.second == ciutat_base))) {

                     if (hi_ha_rivals(ciutat_base)) {
                         if(cell(posicio).type == CITY) {
                             proxim_mov = buscar_matar(posicio,ciutat_base);
                         }
                         else proxim_mov = bfs_lloc(posicio,CITY);

                    }
                     else {
                         if(cell(posicio).type == CITY) {
                             proxim_mov = bfs_lloc(posicio,PATH);
                         }
                         else proxim_mov = bfs_lloc(posicio,CITY);
                     }
             }
            else {
                 proxim_mov = bfs_id(posicio,ciutat_base);
             }


         }
         else if (bfs_lloc_no_conquerit_buit(posicio) != -1) {
             proxim_mov = bfs_lloc_no_conquerit_buit(posicio);
         }
         else if ((!unit(id).mask and  !unit(id).immune)) {
             if (bfs_distancia_mascareta(posicio) <= 2 and bfs_distancia_mascareta(posicio) != -1) proxim_mov = bfs_anar_mascareta(posicio);
             else proxim_mov = bfs_lloc_no_conquerit(posicio);
         }


          else {
              proxim_mov = bfs_lloc_no_conquerit(posicio);
          }
           Pos proxima_pos = proxima_p(posicio, proxim_mov);
           if (cell(proxima_pos).unit_id != -1 and
                 pertany_ales_meves(cell(proxima_pos).unit_id)) {
                     int desviacio = esquivar(proxima_pos,posicio);
                     move(id, Dir(desviacio));
             }
         else move(id,Dir(proxim_mov));
        }

     }


   virtual void play () {
       if (round() == 0){
           vector<Components> v(4);
           quadrants = v;
           identificar_mapa();
           ronda_inicial();
       }


       else move_units();
   }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
