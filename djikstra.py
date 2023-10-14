import heapq

def dijkstra(graph, start):
    # Initialize distances with infinity for all vertices except the start vertex
    distances = {vertex: float('infinity') for vertex in graph}
    distances[start] = 0

    # Priority queue to keep track of vertices to visit next
    priority_queue = [(0, start)]

    while priority_queue:
        # Get the vertex with the smallest distance
        current_distance, current_vertex = heapq.heappop(priority_queue)

        # If the current distance is greater than the recorded distance, skip
        if current_distance > distances[current_vertex]:
            continue

        # Visit all neighbors of the current vertex
        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight

            # If a shorter path is found, update the distance
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances

# Example usage:
graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1}
}

start_vertex = 'A'
shortest_distances = dijkstra(graph, start_vertex)
print("Shortest distances from", start_vertex, "to all vertices:", shortest_distances)
