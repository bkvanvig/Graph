// --------------------------
// projects/c++/graph/Graph.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#ifndef Graph_h
#define Graph_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // size_t
#include <utility> // make_pair, pair
#include <vector>  // vector

// -----
// Graph
// -----

class Graph {
    public:
        // --------
        // typedefs
        // --------

        typedef int vertex_descriptor;  // fix!
        typedef std::pair<vertex_descriptor, vertex_descriptor> edge_descriptor;   

        typedef std::vector<vertex_descriptor>::const_iterator vertex_iterator;   
        typedef std::vector<std::pair<int, int> >::const_iterator edge_iterator;      
        typedef std::vector<vertex_descriptor>::const_iterator adjacency_iterator; 

        typedef std::size_t vertices_size_type;
        typedef std::size_t edges_size_type;

    public:
        // --------
        // add_edge
        // --------

        /**
         * @param vertex_descriptor vd1, first vertex
         * @param vertex_descriptor vd2, second vertex
         * @returns std::pair<edge_descriptor, bool>, first being pair(vd1, vd2) & bool if edge was added or not
         */
        friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor vd1, vertex_descriptor vd2, Graph& g) {
            // <your code>
            edge_descriptor ed = std::make_pair(vd1, vd2);
            bool            b  = false;
            //only add edge if edge doesn't already exist

            if(std::find(g._g.at(vd1).begin(), g._g.at(vd1).end(), vd2) != g._g.at(vd1).end()) {
                b = false;
            } else {
                 /* _g.at(vd1) does not contain vd2 */
                // MUST insert in ordered fashion
                int i;
                auto pos = g._e.begin();
                for (i = 0; i < g._e.size(); ++i)
                {
                    if (g._e.at(i).first > vd1)
                        break;
                    if (g._e.at(i).first == vd1){
                        if (g._e.at(i).second > vd2){
                        break;
                        }
                    }
                    ++pos;
                }
                g._e.insert(pos, ed);
                g._g.at(vd1).push_back(vd2);
                b = true;
            }
            return std::make_pair(ed, b);}

        // ----------
        // add_vertex
        // ----------

        /**
         * @param Graph g
         * @return vertex_descriptor that was added to g
         */
        friend vertex_descriptor add_vertex (Graph& g) {
            // <your code>
            vertex_descriptor v = g._v.size(); 
            g._v.push_back(v);
            g._g.push_back(std::vector<vertex_descriptor>());

            return v;}

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * @param vertex_descriptor vd
         * @param const Graph g
         * @return std::pair<adjacency_iterator, adjacency_iterator> representing beginning and end of vd's adjacent vertices
         */
        friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor vd, const Graph& g) {
            // <your code>
            adjacency_iterator b = g._g.at(vd).begin();
            adjacency_iterator e = g._g.at(vd).end();
            return std::make_pair(b, e);}

        // ----
        // edge
        // ----

        /**
         * @param vertex_descriptor vd1
         * @param vertex_descriptor vd2
         * @param const Graph g
         * @returns std::pair<edge_descriptor, bool> with edge_descriptor being edge between vd1 & vd2 and bool true if edge exists
         */
        friend std::pair<edge_descriptor, bool> edge (vertex_descriptor vd1, vertex_descriptor vd2, const Graph& g) {
            // <your code>
            edge_descriptor ed = std::make_pair(vd1, vd2);
            bool            b  = true;
            if(std::find(g._g.at(vd1).begin(), g._g.at(vd1).end(), vd2) != g._g.at(vd1).end()) {
                b = true;
            } else {
                b = false;
            }
            return std::make_pair(ed, b);}

        // -----
        // edges
        // -----

        /**
         * @param const Graph g
         * @return std::pair<edge_iterator, edge_iterator> of beginning and end of _e
         */
        friend std::pair<edge_iterator, edge_iterator> edges (const Graph& g) {

            edge_iterator b = g._e.begin();
            edge_iterator e = g._e.end();
            return std::make_pair(b, e);}

        // ---------
        // num_edges
        // ---------

        /**
         * @param const Graph g
         * @return edges_size_type, number of edges in g
         */
        friend edges_size_type num_edges (const Graph& g) {
            // <your code>
            edges_size_type s = g._e.size(); 
            return s;}

        // ------------
        // num_vertices
        // ------------

        /**
         * @param const Graph g
         * @return vertices_size_type, number of vertices in g
         */
        friend vertices_size_type num_vertices (const Graph& g) {
            // <your code>
            vertices_size_type s = g._v.size(); 
            return s;}

        // ------
        // source
        // ------

        /**
         * @param edge_descriptor ed
         * @param const Graph g
         * @return vertex_descriptor representing the "source" of edge ed, or the first in pairing
         */
        friend vertex_descriptor source (edge_descriptor ed, const Graph& g) {
            // <your code>

            return ed.first;
        }

        // ------
        // target
        // ------

        /**
         * @param edge_descriptor ed
         * @param const Graph g
         * @return vertex_descriptor representing the "target" of edge ed, or the second in pairing
         */
        friend vertex_descriptor target (edge_descriptor ed, const Graph& g) {
            // <your code>

            return ed.second;
        }

        // ------
        // vertex
        // ------

        /**
         * @param vertices_size_type index
         * @param const Graph g
         * @return vertex_descriptor representing the vertex in g at index
         */
        friend vertex_descriptor vertex (vertices_size_type index, const Graph& g) {
            // <your code>
            
            return g._v.at(index);}

        // --------
        // vertices
        // --------

        /**
         * @param const Graph g
         * @return std::pair<vertex_iterator, vertex_iterator> representing beginning & end of _v
         */
        friend std::pair<vertex_iterator, vertex_iterator> vertices (const Graph& g) {

            vertex_iterator b = g._v.begin();
            vertex_iterator e = g._v.end();
            return std::make_pair(b, e);}

    private:
        // ----
        // data
        // ----

        // 2D vector containing all adjacent edges
        // indexed by vertices
        std::vector< std::vector<vertex_descriptor> >   _g;
        // vector containing all vertices
        std::vector<vertex_descriptor>                  _v; 
        // vector containing all edges
        std::vector<edge_descriptor>                    _e; 

        // -----
        // valid
        // -----

        /**
         * @returns bool, true if object g is valid
         */
        bool valid () const {
            if (_g.size() >=0 && _v.size()>=0 && _e.size()>=0)
                return true;
            return false;
    }

    public:
        // ------------
        // constructors
        // ------------

        /**
         * Creates Graph object
         */
        Graph (std::vector< std::vector<vertex_descriptor> >   g = std::vector< std::vector<vertex_descriptor> >(),
            std::vector<vertex_descriptor>                  v = std::vector<vertex_descriptor>(),
            std::vector<edge_descriptor>                    e = std::vector<edge_descriptor>()  ) :


            _g (g),
            _v (v),
            _e (e){
            
            assert(valid());}

        // Default copy, destructor, and copy assignment
        // Graph  (const Graph<T>&);
        // ~Graph ();
        // Graph& operator = (const Graph&);
    };

#endif // Graph_h
