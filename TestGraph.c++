// --------------------------------
// projects/g++/graph/TestGraph.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <iterator> // ostream_iterator
#include <sstream>  // ostringstream
#include <utility>  // pair

#include "boost/graph/adjacency_list.hpp"  // adjacency_list
#include "boost/graph/topological_sort.hpp"// topological_sort

#include "gtest/gtest.h"

#include "Graph.h"

using namespace std;

using testing::Test;
using testing::Types;

// ---------
// TestGraph
// ---------

template <typename G>
struct TestGraph : Test {
    // --------
    // typedefs
    // --------

    typedef          G                     graph_type;
    typedef typename G::vertex_descriptor  vertex_descriptor;
    typedef typename G::edge_descriptor    edge_descriptor;
    typedef typename G::vertex_iterator    vertex_iterator;
    typedef typename G::edge_iterator      edge_iterator;
    typedef typename G::adjacency_iterator adjacency_iterator;
    typedef typename G::vertices_size_type vertices_size_type;
    typedef typename G::edges_size_type    edges_size_type;};

// directed, sparse, unweighted
// possibly connected
// possibly cyclic
typedef Types<
            boost::adjacency_list<boost::setS, boost::vecS, boost::directedS>,
            Graph>
        graph_types;

TYPED_TEST_CASE(TestGraph, graph_types);

// TYPED_TEST(TestGraph, test_vertex) {
//     typedef typename TestFixture::graph_type         graph_type;
//     typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
//     typedef typename TestFixture::vertices_size_type vertices_size_type;

//     graph_type g;

//     vertex_descriptor vdA = add_vertex(g);

//     vertex_descriptor vd = vertex(0, g);
//     ASSERT_EQ(vdA, vd);

//     vertices_size_type vs = num_vertices(g);
//     ASSERT_EQ(1, vs);}

// TYPED_TEST(TestGraph, test_edge) {
//     typedef typename TestFixture::graph_type         graph_type;
//     typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
//     typedef typename TestFixture::edge_descriptor    edge_descriptor;
//     typedef typename TestFixture::edges_size_type    edges_size_type;

//     graph_type g;
//     //ASSERT_TRUE(g.valid());

//     vertex_descriptor vdA = add_vertex(g);
//     vertex_descriptor vdB = add_vertex(g);

//     edge_descriptor edAB = add_edge(vdA, vdB, g).first;

//     pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
//     ASSERT_EQ(edAB,  p1.first);
//     ASSERT_EQ(false, p1.second);

//     pair<edge_descriptor, bool> p2 = edge(vdA, vdB, g);
//     ASSERT_EQ(edAB, p2.first);
//     ASSERT_EQ(true, p2.second);

//     edges_size_type es = num_edges(g);
//     ASSERT_EQ(1, es);

//     vertex_descriptor vd1 = source(edAB, g);
//     ASSERT_EQ(vdA, vd1);

//     vertex_descriptor vd2 = target(edAB, g);
//     ASSERT_EQ(vdB, vd2);}

// TYPED_TEST(TestGraph, test_vertices) {
//     typedef typename TestFixture::graph_type         graph_type;
//     typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
//     typedef typename TestFixture::vertex_iterator    vertex_iterator;

//     graph_type g;

//     vertex_descriptor vdA = add_vertex(g);
//     vertex_descriptor vdB = add_vertex(g);

//     pair<vertex_iterator, vertex_iterator> p = vertices(g);
//     vertex_iterator                        b = p.first;
//     vertex_iterator                        e = p.second;
//     if (b != e) {
//         vertex_descriptor vd = *b;
//         ASSERT_EQ(vdA, vd);}
//     ++b;
//     if (b != e) {
//         vertex_descriptor vd = *b;
//         ASSERT_EQ(vdB, vd);}
//     ++b;
//     ASSERT_EQ(e, b);}

// TYPED_TEST(TestGraph, test_edges) {
//     typedef typename TestFixture::graph_type         graph_type;
//     typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
//     typedef typename TestFixture::edge_descriptor    edge_descriptor;
//     typedef typename TestFixture::edge_iterator      edge_iterator;

//     graph_type g;

//     vertex_descriptor vdA = add_vertex(g);
//     vertex_descriptor vdB = add_vertex(g);
//     vertex_descriptor vdC = add_vertex(g);

//     edge_descriptor edAB = add_edge(vdA, vdB, g).first;
//     edge_descriptor edAC = add_edge(vdA, vdC, g).first;

//     pair<edge_iterator, edge_iterator> p = edges(g);
//     edge_iterator                      b = p.first;
//     edge_iterator                      e = p.second;
//     if (b != e) {
//         edge_descriptor ed = *b;
//         ASSERT_EQ(edAB, ed);}
//     ++b;
//     if (b != e) {
//         edge_descriptor ed = *b;
//         ASSERT_EQ(edAC, ed);}
//     ++b;
//     ASSERT_EQ(e, b);}

// TYPED_TEST(TestGraph, test_adjacent_vertices) {
//     typedef typename TestFixture::graph_type         graph_type;
//     typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
//     typedef typename TestFixture::adjacency_iterator adjacency_iterator;

//     graph_type g;

//     vertex_descriptor vdA = add_vertex(g);
//     vertex_descriptor vdB = add_vertex(g);
//     vertex_descriptor vdC = add_vertex(g);

//     add_edge(vdA, vdB, g);
//     add_edge(vdA, vdC, g);

//     pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA, g);
//     adjacency_iterator                           b = p.first;
//     adjacency_iterator                           e = p.second;
//     if (b != e) {
//         vertex_descriptor vd = *b;
//         ASSERT_EQ(vdB, vd);}
//     ++b;
//     if (b != e) {
//         vertex_descriptor vd = *b;
//         ASSERT_EQ(vdC, vd);}
//     ++b;
//     ASSERT_EQ(e, b);}


// --------------
// add_edge
// --------------
TYPED_TEST(TestGraph, add_edge_1){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;

    graph_type g;

    vertex_descriptor vd0 = add_vertex(g);
    vertex_descriptor vd1 = add_vertex(g);

    edge_descriptor ed01 = add_edge(vd0, vd1, g).first;
    edge_descriptor ed10 = add_edge(vd1, vd0, g).first;

    ASSERT_EQ(2, num_edges(g));

}

TYPED_TEST(TestGraph, add_edge_2){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;


    graph_type g;

    vertex_descriptor vd0 = add_vertex(g);
    vertex_descriptor vd1 = add_vertex(g);

    edge_descriptor ed01 = add_edge(vd0, vd1, g).first;
    edge_descriptor ed10 = add_edge(vd1, vd0, g).first;

    ASSERT_EQ(2, num_edges(g));
    
}
TYPED_TEST(TestGraph, add_edge_3){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;

    graph_type g;

    vertex_descriptor vd0 = add_vertex(g);
    vertex_descriptor vd1 = add_vertex(g);

    edge_descriptor ed01 = add_edge(vd0, vd1, g).first;
    edge_descriptor ed10 = add_edge(vd1, vd0, g).first;

    ASSERT_EQ(2, num_edges(g));
    
}
// --------------
// add_vertex
// --------------
TYPED_TEST(TestGraph, add_vertex_1){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;;
    typedef typename TestFixture::vertices_size_type vertices_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);

    vertex_descriptor vd = vertex(0, g);
    ASSERT_EQ(vdA, vd);

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(1, vs);
}

TYPED_TEST(TestGraph, add_vertex_2){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;;
    typedef typename TestFixture::vertices_size_type vertices_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    vertex_descriptor vd1 = vertex(0, g);
    ASSERT_EQ(vdA, vd1);

    vertex_descriptor vd2 = vertex(1, g);
    ASSERT_EQ(vdB, vd2);

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(2, vs);
    
}

TYPED_TEST(TestGraph, add_vertex_3){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;;
    typedef typename TestFixture::vertices_size_type vertices_size_type;

    graph_type g;
    int n = 100;
    for (vertex_descriptor v = 0; v < n; ++v)
    {
        vertex_descriptor vdA = add_vertex(g);
        ASSERT_EQ(vdA, vertex(v, g));
    }

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(n, vs);
    
}

TYPED_TEST(TestGraph, add_vertex_4){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;;
    typedef typename TestFixture::vertices_size_type vertices_size_type;

    graph_type g;
    int n = 10000;
    for (vertex_descriptor v = 0; v < n; ++v)
    {
        vertex_descriptor vdA = add_vertex(g);
        ASSERT_EQ(vdA, vertex(v, g));
    }

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(n, vs);
    
}
TYPED_TEST(TestGraph, add_vertex_5){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;;
    typedef typename TestFixture::vertices_size_type vertices_size_type;

    graph_type g;
    int n = 1000000;
    for (vertex_descriptor v = 0; v < n; ++v)
    {
        vertex_descriptor vdA = add_vertex(g);
        ASSERT_EQ(vdA, vertex(v, g));
    }

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(n, vs);
    
}

// ------------------
// adjacent_vertices
// ------------------
TYPED_TEST(TestGraph, adjacent_vertices_1){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    add_edge(vdA, vdB, g);

    pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA, g);
    adjacency_iterator                           b = p.first;
    adjacency_iterator                           e = p.second;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdB, vd);}
    ++b;
    ASSERT_EQ(e, b);
}

TYPED_TEST(TestGraph, adjacent_vertices_2){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);

    add_edge(vdA, vdB, g);
    add_edge(vdA, vdC, g);

    pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA, g);
    adjacency_iterator                           b = p.first;
    adjacency_iterator                           e = p.second;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdB, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdC, vd);}
    ++b;
    ASSERT_EQ(e, b);
    
}
TYPED_TEST(TestGraph, adjacent_vertices_3){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;

    graph_type g;

    vertex_descriptor vd0 = add_vertex(g);
    vertex_descriptor vd1 = add_vertex(g);
    vertex_descriptor vd2 = add_vertex(g);
    vertex_descriptor vd3 = add_vertex(g);
    vertex_descriptor vd4 = add_vertex(g);

    add_edge(vd0, vd1, g);
    add_edge(vd0, vd2, g);
    add_edge(vd0, vd3, g);
    add_edge(vd0, vd4, g);

    pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vd0, g);
    adjacency_iterator b = p.first;
    adjacency_iterator e = p.second;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vd1, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vd2, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vd3, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vd4, vd);}
    ++b;
    ASSERT_EQ(e, b);
    
}
    
// --------------
// edge
// --------------
TYPED_TEST(TestGraph, edge_1){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;

    pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    ASSERT_EQ(edAB,  p1.first);
    ASSERT_EQ(false, p1.second);

    pair<edge_descriptor, bool> p2 = edge(vdA, vdB, g);
    ASSERT_EQ(edAB, p2.first);
    ASSERT_EQ(true, p2.second);

    edges_size_type es = num_edges(g);
    ASSERT_EQ(1, es);

}

TYPED_TEST(TestGraph, edge_2){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;

    pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    ASSERT_EQ(edAB,  p1.first);
    ASSERT_EQ(false, p1.second);

    pair<edge_descriptor, bool> p2 = edge(vdA, vdB, g);
    ASSERT_EQ(edAB, p2.first);
    ASSERT_EQ(true, p2.second);

    edge_descriptor edCD = add_edge(vdC, vdD, g).first;

    pair<edge_descriptor, bool> p3 = add_edge(vdC, vdD, g);
    ASSERT_EQ(edCD,  p3.first);
    ASSERT_EQ(false, p3.second);

    pair<edge_descriptor, bool> p4 = edge(vdC, vdD, g);
    ASSERT_EQ(edCD, p4.first);
    ASSERT_EQ(true, p4.second);

    edges_size_type es = num_edges(g);
    ASSERT_EQ(2, es);

}
TYPED_TEST(TestGraph, edge_3){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    add_edge(vdB, vdB, g).first;

    ASSERT_EQ(1, num_edges(g));
}

// --------------
// edges
// --------------
TYPED_TEST(TestGraph, edges_1){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::edge_iterator      edge_iterator;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;
    edge_descriptor edBA = add_edge(vdB, vdA, g).first;

    pair<edge_iterator, edge_iterator> p = edges(g);
    edge_iterator                      b = p.first;
    edge_iterator                      e = p.second;
    if (b != e) {
        edge_descriptor ed = *b;
        ASSERT_EQ(edAB, ed);}
    ++b;
    if (b != e) {
        edge_descriptor ed = *b;
        ASSERT_EQ(edBA, ed);}
    ++b;
    ASSERT_EQ(e, b);

}

TYPED_TEST(TestGraph, edges_2){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::edge_iterator      edge_iterator;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);

    edge_descriptor edBA = add_edge(vdB, vdA, g).first;
    edge_descriptor edBB = add_edge(vdB, vdB, g).first;
    edge_descriptor edBC = add_edge(vdB, vdC, g).first;
    edge_descriptor edBD = add_edge(vdB, vdD, g).first;
    

    pair<edge_iterator, edge_iterator> p = edges(g);
    edge_iterator                      b = p.first;
    edge_iterator                      e = p.second;

    if (b != e) {
        edge_descriptor ed = *b;
        ASSERT_EQ(edBA, ed);}
    ++b;
    if (b != e) {
        edge_descriptor ed = *b;
        ASSERT_EQ(edBB, ed);}
    ++b;
    if (b != e) {
        edge_descriptor ed = *b;
        ASSERT_EQ(edBC, ed);}
    ++b;
    if (b != e) {
        edge_descriptor ed = *b;
        ASSERT_EQ(edBD, ed);}
    ++b;

    ASSERT_EQ(e, b);
    
}
TYPED_TEST(TestGraph, edges_3){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::edge_iterator      edge_iterator;

    graph_type g;

    vertex_descriptor vd0 = add_vertex(g);
    vertex_descriptor vd1 = add_vertex(g);
    vertex_descriptor vd2 = add_vertex(g);
    vertex_descriptor vd3 = add_vertex(g);
    vertex_descriptor vd4 = add_vertex(g);

    edge_descriptor ed01 = add_edge(vd0, vd1, g).first;
    edge_descriptor ed12 = add_edge(vd1, vd2, g).first;
    edge_descriptor ed14 = add_edge(vd1, vd4, g).first;
    edge_descriptor ed23 = add_edge(vd2, vd3, g).first;
    edge_descriptor ed24 = add_edge(vd2, vd4, g).first;
    edge_descriptor ed40 = add_edge(vd4, vd0, g).first;

    pair<edge_iterator, edge_iterator> p = edges(g);
    edge_iterator b = p.first;
    edge_iterator e = p.second;
    if (b != e) {
        edge_descriptor ed = *b;
        ASSERT_EQ(ed01, ed);}
    ++b;
    if (b != e) {
        edge_descriptor ed = *b;
        ASSERT_EQ(ed12, ed);}
    ++b;
    if (b != e) {
        edge_descriptor ed = *b;
        ASSERT_EQ(ed14, ed);}
    ++b;
    if (b != e) {
        edge_descriptor ed = *b;
        ASSERT_EQ(ed23, ed);}
    ++b;
    if (b != e) {
        edge_descriptor ed = *b;
        ASSERT_EQ(ed24, ed);}
    ++b;
    if (b != e) {
        edge_descriptor ed = *b;
        ASSERT_EQ(ed40, ed);}
    ++b;
    ASSERT_EQ(b, e);
    
}

// --------------
// num_edges
// --------------
TYPED_TEST(TestGraph, num_edges_1){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);

    edge_descriptor edBA = add_edge(vdB, vdA, g).first;

    ASSERT_EQ(num_edges(g), 1);

}

TYPED_TEST(TestGraph, num_edges_2){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);

    edge_descriptor edBA = add_edge(vdB, vdA, g).first;
    edge_descriptor edBB = add_edge(vdB, vdB, g).first;
    edge_descriptor edBC = add_edge(vdB, vdC, g).first;
    edge_descriptor edBD = add_edge(vdB, vdD, g).first;

    ASSERT_EQ(num_edges(g), 4);
    
}
TYPED_TEST(TestGraph, num_edges_3){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);

    edge_descriptor edAA = add_edge(vdA, vdA, g).first;
    edge_descriptor edAB = add_edge(vdA, vdB, g).first;
    edge_descriptor edAC = add_edge(vdA, vdC, g).first;
    edge_descriptor edAD = add_edge(vdA, vdD, g).first;
    edge_descriptor edBA = add_edge(vdB, vdA, g).first;
    edge_descriptor edBB = add_edge(vdB, vdB, g).first;
    edge_descriptor edBC = add_edge(vdB, vdC, g).first;
    edge_descriptor edBD = add_edge(vdB, vdD, g).first;
    edge_descriptor edCA = add_edge(vdC, vdA, g).first;
    edge_descriptor edCB = add_edge(vdC, vdB, g).first;
    edge_descriptor edCC = add_edge(vdC, vdC, g).first;
    edge_descriptor edCD = add_edge(vdC, vdD, g).first;
    edge_descriptor edDA = add_edge(vdD, vdA, g).first;
    edge_descriptor edDB = add_edge(vdD, vdB, g).first;
    edge_descriptor edDC = add_edge(vdD, vdC, g).first;
    edge_descriptor edDD = add_edge(vdD, vdD, g).first;

    ASSERT_EQ(num_edges(g), 16);
    
}
    
// --------------
// num_vertices
// --------------
TYPED_TEST(TestGraph, num_vertices_1){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);

    ASSERT_EQ(num_vertices(g), 1);

}

TYPED_TEST(TestGraph, num_vertices_2){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;

    graph_type g;

    int n = 1000;

    for (int i = 0; i < n; ++i)
    {
        vertex_descriptor vdA = add_vertex(g);
    }

    ASSERT_EQ(num_vertices(g), n);
    
}
TYPED_TEST(TestGraph, num_vertices_3){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;

    graph_type g;

    int n = 0;

    for (int i = 0; i < n; ++i)
    {
        vertex_descriptor vdA = add_vertex(g);
    }

    ASSERT_EQ(num_vertices(g), n);
}

// --------------
// source
// --------------
TYPED_TEST(TestGraph, source_1){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);

    edge_descriptor edAA = add_edge(vdA, vdA, g).first;
    edge_descriptor edAB = add_edge(vdA, vdB, g).first;
    edge_descriptor edAC = add_edge(vdA, vdC, g).first;
    edge_descriptor edAD = add_edge(vdA, vdD, g).first;
    edge_descriptor edBA = add_edge(vdB, vdA, g).first;
    edge_descriptor edBB = add_edge(vdB, vdB, g).first;
    edge_descriptor edBC = add_edge(vdB, vdC, g).first;
    edge_descriptor edBD = add_edge(vdB, vdD, g).first;
    edge_descriptor edCA = add_edge(vdC, vdA, g).first;
    edge_descriptor edCB = add_edge(vdC, vdB, g).first;
    edge_descriptor edCC = add_edge(vdC, vdC, g).first;
    edge_descriptor edCD = add_edge(vdC, vdD, g).first;
    edge_descriptor edDA = add_edge(vdD, vdA, g).first;
    edge_descriptor edDB = add_edge(vdD, vdB, g).first;
    edge_descriptor edDC = add_edge(vdD, vdC, g).first;
    edge_descriptor edDD = add_edge(vdD, vdD, g).first;

    ASSERT_EQ(source(edAA, g), vdA);
    ASSERT_EQ(source(edAB, g), vdA);
    ASSERT_EQ(source(edAC, g), vdA);
    ASSERT_EQ(source(edAD, g), vdA);
    ASSERT_EQ(source(edBA, g), vdB);
    ASSERT_EQ(source(edBB, g), vdB);
    ASSERT_EQ(source(edBC, g), vdB);
    ASSERT_EQ(source(edBD, g), vdB);
    ASSERT_EQ(source(edCA, g), vdC);
    ASSERT_EQ(source(edCB, g), vdC);
    ASSERT_EQ(source(edCC, g), vdC);
    ASSERT_EQ(source(edCD, g), vdC);
    ASSERT_EQ(source(edDA, g), vdD);
    ASSERT_EQ(source(edDB, g), vdD);
    ASSERT_EQ(source(edDC, g), vdD);
    ASSERT_EQ(source(edDD, g), vdD);

}

TYPED_TEST(TestGraph, source_2){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);

    edge_descriptor edAA = add_edge(vdA, vdA, g).first;
    edge_descriptor edBB = add_edge(vdB, vdB, g).first;
    edge_descriptor edCC = add_edge(vdC, vdC, g).first;
    edge_descriptor edDD = add_edge(vdD, vdD, g).first;

    ASSERT_EQ(source(edAA, g), vdA);
    ASSERT_EQ(source(edBB, g), vdB);
    ASSERT_EQ(source(edCC, g), vdC);
    ASSERT_EQ(source(edDD, g), vdD);
    
}
TYPED_TEST(TestGraph, source_3){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);

    edge_descriptor edAA = add_edge(vdA, vdA, g).first;

    int n = 100;

    for (int i = 0; i < n; ++i)
    {
        add_edge(vdB, vdD, g);
    }

    ASSERT_EQ(source(edAA, g), vdA);
}
   
// --------------
// target
// --------------
TYPED_TEST(TestGraph, target_1){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);

    edge_descriptor edAA = add_edge(vdA, vdA, g).first;
    edge_descriptor edAB = add_edge(vdA, vdB, g).first;
    edge_descriptor edAC = add_edge(vdA, vdC, g).first;
    edge_descriptor edAD = add_edge(vdA, vdD, g).first;
    edge_descriptor edBA = add_edge(vdB, vdA, g).first;
    edge_descriptor edBB = add_edge(vdB, vdB, g).first;
    edge_descriptor edBC = add_edge(vdB, vdC, g).first;
    edge_descriptor edBD = add_edge(vdB, vdD, g).first;
    edge_descriptor edCA = add_edge(vdC, vdA, g).first;
    edge_descriptor edCB = add_edge(vdC, vdB, g).first;
    edge_descriptor edCC = add_edge(vdC, vdC, g).first;
    edge_descriptor edCD = add_edge(vdC, vdD, g).first;
    edge_descriptor edDA = add_edge(vdD, vdA, g).first;
    edge_descriptor edDB = add_edge(vdD, vdB, g).first;
    edge_descriptor edDC = add_edge(vdD, vdC, g).first;
    edge_descriptor edDD = add_edge(vdD, vdD, g).first;

    ASSERT_EQ(target(edAA, g), vdA);
    ASSERT_EQ(target(edAB, g), vdB);
    ASSERT_EQ(target(edAC, g), vdC);
    ASSERT_EQ(target(edAD, g), vdD);
    ASSERT_EQ(target(edBA, g), vdA);
    ASSERT_EQ(target(edBB, g), vdB);
    ASSERT_EQ(target(edBC, g), vdC);
    ASSERT_EQ(target(edBD, g), vdD);
    ASSERT_EQ(target(edCA, g), vdA);
    ASSERT_EQ(target(edCB, g), vdB);
    ASSERT_EQ(target(edCC, g), vdC);
    ASSERT_EQ(target(edCD, g), vdD);
    ASSERT_EQ(target(edDA, g), vdA);
    ASSERT_EQ(target(edDB, g), vdB);
    ASSERT_EQ(target(edDC, g), vdC);
    ASSERT_EQ(target(edDD, g), vdD);

}

TYPED_TEST(TestGraph, target_2){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);

    edge_descriptor edAA = add_edge(vdA, vdA, g).first;
    edge_descriptor edBB = add_edge(vdB, vdB, g).first;
    edge_descriptor edCC = add_edge(vdC, vdC, g).first;
    edge_descriptor edDD = add_edge(vdD, vdD, g).first;

    ASSERT_EQ(target(edAA, g), vdA);
    ASSERT_EQ(target(edBB, g), vdB);
    ASSERT_EQ(target(edCC, g), vdC);
    ASSERT_EQ(target(edDD, g), vdD);
    
}
TYPED_TEST(TestGraph, target_3){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;

    int n = 100;

    for (int i = 0; i < n; ++i)
    {
        add_edge(vdB, vdD, g);
    }

    ASSERT_EQ(target(edAB, g), vdB);
    
}

// --------------
// vertex
// --------------
TYPED_TEST(TestGraph, vertex_1){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::vertices_size_type vertices_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);

    vertex_descriptor vd = vertex(0, g);
    ASSERT_EQ(vdA, vd);

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(1, vs);

}

TYPED_TEST(TestGraph, vertex_2){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::vertices_size_type vertices_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    vertex_descriptor vd1 = vertex(0, g);
    ASSERT_EQ(vdA, vd1);

    vertex_descriptor vd2 = vertex(1, g);
    ASSERT_EQ(vdB, vd2);

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(2, vs);
    
}
TYPED_TEST(TestGraph, vertex_3){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::vertices_size_type vertices_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);
    vertex_descriptor vdE = add_vertex(g);
    vertex_descriptor vdF = add_vertex(g);

    vertex_descriptor vd0 = vertex(0, g);
    ASSERT_EQ(vdA, vd0);

    vertex_descriptor vd1 = vertex(1, g);
    ASSERT_EQ(vdB, vd1);

    vertex_descriptor vd2 = vertex(2, g);
    ASSERT_EQ(vdC, vd2);

    vertex_descriptor vd3 = vertex(3, g);
    ASSERT_EQ(vdD, vd3);

    vertex_descriptor vd4 = vertex(4, g);
    ASSERT_EQ(vdE, vd4);

    vertex_descriptor vd5 = vertex(5, g);
    ASSERT_EQ(vdF, vd5);

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(6, vs);
    
}
TYPED_TEST(TestGraph, vertex_4){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;

    graph_type g;

    vertex_descriptor vd_array[10000];
    for(int i=0; i<10000; ++i) {
        vd_array[i] = add_vertex(g);}
    for(int i=0; i<10000; ++i)
        ASSERT_EQ(vd_array[i], vertex(i, g));
}
    
// --------------
// vertices
// --------------
TYPED_TEST(TestGraph, vertices_1){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    pair<vertex_iterator, vertex_iterator> p = vertices(g);
    vertex_iterator                        b = p.first;
    vertex_iterator                        e = p.second;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdA, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdB, vd);}
    ++b;
    ASSERT_EQ(e, b);

}

TYPED_TEST(TestGraph, vertices_2){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);
    vertex_descriptor vdE = add_vertex(g);
    vertex_descriptor vdF = add_vertex(g);

    pair<vertex_iterator, vertex_iterator> p = vertices(g);
    vertex_iterator                        b = p.first;
    vertex_iterator                        e = p.second;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdA, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdB, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdC, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdD, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdE, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdF, vd);}
    ++b;
    ASSERT_EQ(e, b);
    
}
TYPED_TEST(TestGraph, vertices_3){
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);

    vertex_descriptor vdG = add_vertex(g);
    vertex_descriptor vdH = add_vertex(g);
    vertex_descriptor vdI = add_vertex(g);

    vertex_descriptor vdD = add_vertex(g);
    vertex_descriptor vdE = add_vertex(g);
    vertex_descriptor vdF = add_vertex(g);

    vertex_descriptor vdJ = add_vertex(g);
    vertex_descriptor vdK = add_vertex(g);
    vertex_descriptor vdL = add_vertex(g);

    pair<vertex_iterator, vertex_iterator> p = vertices(g);
    vertex_iterator                        b = p.first;
    vertex_iterator                        e = p.second;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdA, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdB, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdC, vd);}
    ++b;
        if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdG, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdH, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdI, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdD, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdE, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdF, vd);}
    ++b;

    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdJ, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdK, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdL, vd);}
    ++b;
    ASSERT_EQ(e, b);
    
}
