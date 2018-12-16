//
//  mesh.cpp
//  
//
//  Created by David Tiobang on 16/12/2018.
//

#include "mesh.hpp"
#include "params.hpp"
#include "solver.hpp"
#include <cmath>
#include <limits>
#include <algorithm>
#include <cstdlib>

namespace dauphine
{
    Mesh::Mesh(double dt, double dx,double maturity, double spot, std::vector<double> spot_boundaries, std::vector<double> boundaries)
    : m_spot_boundaries(boundaries),p(dt,dx,maturity,spot,spot_boundaries)
    {
    }
    
    Mesh::~Mesh()
    {
    }
    
    std::vector<double> Mesh::get_mesh_spot_boundaries() const
    {
        return m_spot_boundaries;
    }
    
    
    std::vector<double> Mesh::spot_vector(params p)
    {
        int size = floor((m_spot_boundaries[0] - m_spot_boundaries[1]) / p.get_dx())+1;
        std::vector<double> result(size);
        for (std::size_t i = 0; i < result.size(); ++i)
            {
                result[i] =log(m_spot_boundaries[1]+i*p.get_dx());
            }
        return result;
    }





}