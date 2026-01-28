<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
struct NetworkParams {
    int N, S, L; 
    int M, K, P; 
    int R;       
    int SP;      
    int MP;      
};
struct Flow {
    int id;
    int gA, lA, gB, lB;
};
struct Route {
    int sA, kA, m, sB, kB;
};
int get_port_num(int g, int s, int k, const NetworkParams& params) {
    return g * params.SP * params.K + (s % params.SP) * params.K + k;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    NetworkParams params;
    std::cin >> params.N >> params.S >> params.L;
    std::cin >> params.M >> params.K >> params.P;
    params.R = params.N * (params.S / params.P) * params.K;
    params.SP = params.S / params.P;
    params.MP = params.M / params.P;
    std::vector<std::vector<int>> prev_oxc_config(params.M, std::vector<int>(params.R, -1));
    std::vector<int> spine_plane(params.S);
    for(int i = 0; i < params.S; ++i) spine_plane[i] = i / params.SP;
    std::vector<int> oxc_plane(params.M);
    for(int i = 0; i < params.M; ++i) oxc_plane[i] = i / params.MP;
    for (int q = 0; q < 5; ++q) {
        int Q;
        std::cin >> Q;
        std::vector<Flow> flows(Q);
        for (int i = 0; i < Q; ++i) {
            flows[i].id = i;
            std::cin >> flows[i].gA >> flows[i].lA >> flows[i].gB >> flows[i].lB;
        }
        std::vector<Route> routes(Q);
        std::vector<std::vector<int>> current_oxc_config(params.M, std::vector<int>(params.R, -1));
        std::vector<std::vector<std::vector<int>>> leaf_spine_usage(params.N, std::vector<std::vector<int>>(params.L, std::vector<int>(params.S, 0)));
        std::vector<std::vector<std::vector<std::vector<int>>>> spine_oxc_usage(params.N, std::vector<std::vector<std::vector<int>>>(params.S, std::vector<std::vector<int>>(params.M, std::vector<int>(params.K, 0))));
        std::vector<std::vector<bool>> oxc_port_used(params.M, std::vector<bool>(params.R, false));
                std::vector<std::vector<std::vector<int>>> available_spines(params.N, std::vector<std::vector<int>>(params.L));
                for(int g=0; g<params.N; ++g) {
                    for(int l=0; l<params.L; ++l) {
                        available_spines[g][l].resize(params.S);
                        std::iota(available_spines[g][l].begin(), available_spines[g][l].end(), 0);
                    }
                }
                std::sort(flows.begin(), flows.end(), [&](const Flow& a, const Flow& b) {
                    long long a_constraints = (long long)available_spines[a.gA][a.lA].size() * available_spines[a.gB][a.lB].size();
                    long long b_constraints = (long long)available_spines[b.gA][b.lA].size() * available_spines[b.gB][b.lB].size();
                    return a_constraints < b_constraints;
                });
                for (const auto& flow : flows) {
                    long long best_cost = -1;
                    Route best_route = {-1, -1, -1, -1, -1};
                    int sA_idx_to_erase = -1;
                    int sB_idx_to_erase = -1;
                    const auto& available_sA = available_spines[flow.gA][flow.lA];
                    const auto& available_sB = available_spines[flow.gB][flow.lB];
                    for (size_t i = 0; i < available_sA.size(); ++i) {
                        int sA = available_sA[i];
                        int p = spine_plane[sA];
                        for (size_t j = 0; j < available_sB.size(); ++j) {
                            int sB = available_sB[j];
                            if (spine_plane[sB] != p) continue;
                            for (int m_idx = 0; m_idx < params.MP; ++m_idx) {
                                int m = p * params.MP + m_idx;
                                for (int kA = 0; kA < params.K; ++kA) {
                                    for (int kB = 0; kB < params.K; ++kB) {
                                        int portA = get_port_num(flow.gA, sA, kA, params);
                                        int portB = get_port_num(flow.gB, sB, kB, params);
                                        if (oxc_port_used[m][portA] || oxc_port_used[m][portB]) {
                                            continue;
                                        }
                                        long long current_cost = 0;
                                        current_cost += std::pow(100, leaf_spine_usage[flow.gA][flow.lA][sA]);
                                        current_cost += std::pow(100, leaf_spine_usage[flow.gB][flow.lB][sB]);
                                        current_cost += std::pow(100, spine_oxc_usage[flow.gA][sA][m][kA]);
                                        current_cost += std::pow(100, spine_oxc_usage[flow.gB][sB][m][kB]);
                                        int adj_cost = 0;
                                        if (prev_oxc_config[m][portA] != portB) {
                                           adj_cost = 1; 
                                        }
                                        current_cost += adj_cost;
                                        if (best_cost == -1 || current_cost < best_cost) {
                                            best_cost = current_cost;
                                            best_route = {sA, kA, m, sB, kB};
                                            sA_idx_to_erase = i;
                                            sB_idx_to_erase = j;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if(best_route.sA != -1) {
                        routes[flow.id] = best_route;
                        int portA = get_port_num(flow.gA, best_route.sA, best_route.kA, params);
                        int portB = get_port_num(flow.gB, best_route.sB, best_route.kB, params);
                        current_oxc_config[best_route.m][portA] = portB;
                        current_oxc_config[best_route.m][portB] = portA;
                        oxc_port_used[best_route.m][portA] = true;
                        oxc_port_used[best_route.m][portB] = true;
                        leaf_spine_usage[flow.gA][flow.lA][best_route.sA]++;
                        leaf_spine_usage[flow.gB][flow.lB][best_route.sB]++;
                        spine_oxc_usage[flow.gA][best_route.sA][best_route.m][best_route.kA]++;
                        spine_oxc_usage[flow.gB][best_route.sB][best_route.m][best_route.kB]++;
                        if (sA_idx_to_erase != -1)
                            available_spines[flow.gA][flow.lA].erase(available_spines[flow.gA][flow.lA].begin() + sA_idx_to_erase);
                        if (sB_idx_to_erase != -1)
                            available_spines[flow.gB][flow.lB].erase(available_spines[flow.gB][flow.lB].begin() + sB_idx_to_erase);
                    } else {
                         routes[flow.id] = {0,0,0,0,0}; 
                    }
                }
                for (int i = 0; i < params.M; ++i) {
                    for (int j = 0; j < params.R; ++j) {
                        std::cout << current_oxc_config[i][j] << (j == params.R - 1 ? "" : " ");
                    }
                    std::cout << "\n";
                }
                for (int i = 0; i < Q; ++i) {
                    std::cout << routes[i].sA << " " << routes[i].kA << " " << routes[i].m << " " << routes[i].sB << " " << routes[i].kB << "\n";
                }
                prev_oxc_config = current_oxc_config;
            }
    return 0;
=======
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
struct NetworkParams {
    int N, S, L; 
    int M, K, P; 
    int R;       
    int SP;      
    int MP;      
};
struct Flow {
    int id;
    int gA, lA, gB, lB;
};
struct Route {
    int sA, kA, m, sB, kB;
};
int get_port_num(int g, int s, int k, const NetworkParams& params) {
    return g * params.SP * params.K + (s % params.SP) * params.K + k;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    NetworkParams params;
    std::cin >> params.N >> params.S >> params.L;
    std::cin >> params.M >> params.K >> params.P;
    params.R = params.N * (params.S / params.P) * params.K;
    params.SP = params.S / params.P;
    params.MP = params.M / params.P;
    std::vector<std::vector<int>> prev_oxc_config(params.M, std::vector<int>(params.R, -1));
    std::vector<int> spine_plane(params.S);
    for(int i = 0; i < params.S; ++i) spine_plane[i] = i / params.SP;
    std::vector<int> oxc_plane(params.M);
    for(int i = 0; i < params.M; ++i) oxc_plane[i] = i / params.MP;
    for (int q = 0; q < 5; ++q) {
        int Q;
        std::cin >> Q;
        std::vector<Flow> flows(Q);
        for (int i = 0; i < Q; ++i) {
            flows[i].id = i;
            std::cin >> flows[i].gA >> flows[i].lA >> flows[i].gB >> flows[i].lB;
        }
        std::vector<Route> routes(Q);
        std::vector<std::vector<int>> current_oxc_config(params.M, std::vector<int>(params.R, -1));
        std::vector<std::vector<std::vector<int>>> leaf_spine_usage(params.N, std::vector<std::vector<int>>(params.L, std::vector<int>(params.S, 0)));
        std::vector<std::vector<std::vector<std::vector<int>>>> spine_oxc_usage(params.N, std::vector<std::vector<std::vector<int>>>(params.S, std::vector<std::vector<int>>(params.M, std::vector<int>(params.K, 0))));
        std::vector<std::vector<bool>> oxc_port_used(params.M, std::vector<bool>(params.R, false));
                std::vector<std::vector<std::vector<int>>> available_spines(params.N, std::vector<std::vector<int>>(params.L));
                for(int g=0; g<params.N; ++g) {
                    for(int l=0; l<params.L; ++l) {
                        available_spines[g][l].resize(params.S);
                        std::iota(available_spines[g][l].begin(), available_spines[g][l].end(), 0);
                    }
                }
                std::sort(flows.begin(), flows.end(), [&](const Flow& a, const Flow& b) {
                    long long a_constraints = (long long)available_spines[a.gA][a.lA].size() * available_spines[a.gB][a.lB].size();
                    long long b_constraints = (long long)available_spines[b.gA][b.lA].size() * available_spines[b.gB][b.lB].size();
                    return a_constraints < b_constraints;
                });
                for (const auto& flow : flows) {
                    long long best_cost = -1;
                    Route best_route = {-1, -1, -1, -1, -1};
                    int sA_idx_to_erase = -1;
                    int sB_idx_to_erase = -1;
                    const auto& available_sA = available_spines[flow.gA][flow.lA];
                    const auto& available_sB = available_spines[flow.gB][flow.lB];
                    for (size_t i = 0; i < available_sA.size(); ++i) {
                        int sA = available_sA[i];
                        int p = spine_plane[sA];
                        for (size_t j = 0; j < available_sB.size(); ++j) {
                            int sB = available_sB[j];
                            if (spine_plane[sB] != p) continue;
                            for (int m_idx = 0; m_idx < params.MP; ++m_idx) {
                                int m = p * params.MP + m_idx;
                                for (int kA = 0; kA < params.K; ++kA) {
                                    for (int kB = 0; kB < params.K; ++kB) {
                                        int portA = get_port_num(flow.gA, sA, kA, params);
                                        int portB = get_port_num(flow.gB, sB, kB, params);
                                        if (oxc_port_used[m][portA] || oxc_port_used[m][portB]) {
                                            continue;
                                        }
                                        long long current_cost = 0;
                                        current_cost += std::pow(100, leaf_spine_usage[flow.gA][flow.lA][sA]);
                                        current_cost += std::pow(100, leaf_spine_usage[flow.gB][flow.lB][sB]);
                                        current_cost += std::pow(100, spine_oxc_usage[flow.gA][sA][m][kA]);
                                        current_cost += std::pow(100, spine_oxc_usage[flow.gB][sB][m][kB]);
                                        int adj_cost = 0;
                                        if (prev_oxc_config[m][portA] != portB) {
                                           adj_cost = 1; 
                                        }
                                        current_cost += adj_cost;
                                        if (best_cost == -1 || current_cost < best_cost) {
                                            best_cost = current_cost;
                                            best_route = {sA, kA, m, sB, kB};
                                            sA_idx_to_erase = i;
                                            sB_idx_to_erase = j;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if(best_route.sA != -1) {
                        routes[flow.id] = best_route;
                        int portA = get_port_num(flow.gA, best_route.sA, best_route.kA, params);
                        int portB = get_port_num(flow.gB, best_route.sB, best_route.kB, params);
                        current_oxc_config[best_route.m][portA] = portB;
                        current_oxc_config[best_route.m][portB] = portA;
                        oxc_port_used[best_route.m][portA] = true;
                        oxc_port_used[best_route.m][portB] = true;
                        leaf_spine_usage[flow.gA][flow.lA][best_route.sA]++;
                        leaf_spine_usage[flow.gB][flow.lB][best_route.sB]++;
                        spine_oxc_usage[flow.gA][best_route.sA][best_route.m][best_route.kA]++;
                        spine_oxc_usage[flow.gB][best_route.sB][best_route.m][best_route.kB]++;
                        if (sA_idx_to_erase != -1)
                            available_spines[flow.gA][flow.lA].erase(available_spines[flow.gA][flow.lA].begin() + sA_idx_to_erase);
                        if (sB_idx_to_erase != -1)
                            available_spines[flow.gB][flow.lB].erase(available_spines[flow.gB][flow.lB].begin() + sB_idx_to_erase);
                    } else {
                         routes[flow.id] = {0,0,0,0,0}; 
                    }
                }
                for (int i = 0; i < params.M; ++i) {
                    for (int j = 0; j < params.R; ++j) {
                        std::cout << current_oxc_config[i][j] << (j == params.R - 1 ? "" : " ");
                    }
                    std::cout << "\n";
                }
                for (int i = 0; i < Q; ++i) {
                    std::cout << routes[i].sA << " " << routes[i].kA << " " << routes[i].m << " " << routes[i].sB << " " << routes[i].kB << "\n";
                }
                prev_oxc_config = current_oxc_config;
            }
    return 0;
>>>>>>> f4a3ee5404bcb997bd906211f57ce621ed833c48
}