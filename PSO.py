import random

# Define the fitness function
def fitness_function(x):
    return (1 + 2 * x - x**2)

# PSO parameters
swarm_size = 5
max_iterations = 4
w = 0.7  # Inertia weight
c1 = 0.2  # Cognitive learning coefficient
c2 = 0.6  # Social learning coefficient

# Initialize the swarm with random positions and zero velocities
swarm = [{'position': random.uniform(-5, 5), 'velocity': random.uniform(0, 0)} for x in range(swarm_size)]

# Initialize personal best (pBest) and global best (gBest)
pBest = [{'position': particle['position'], 'fitness': float('1000')} for particle in swarm]
gBest = {'position': None, 'fitness': float('-1000')}  
# Replace 1000 with inf if needed

temp=1
print("Initial Positions & Velocities:\n")
for j in swarm:
        print("Particle ",temp,":",j)
        temp+=1; 
print()

# The Iteration
for iteration in range(max_iterations):
    temp=1
    print("Iteration ",iteration+1,":")
    print()
    for i, particle in enumerate(swarm):
        # Evaluate fitness
        fitness = fitness_function(particle['position'])
        
        # Update personal best (pBest)
        if fitness > pBest[i]['fitness']:
            pBest[i]['position'] = particle['position']
            pBest[i]['fitness'] = fitness
        
        # Update global best (gBest)
        if fitness > gBest['fitness']:
            gBest['position'] = particle['position']
            gBest['fitness'] = fitness

        print("Personal Best Position for Particle",i+1,"is ",pBest[i]['position'])
        # Update velocity and position
        r1 = random.random()
        r2 = random.random()
        particle['velocity'] = w * particle['velocity'] + c1 * r1 * (pBest[i]['position'] - particle['position']) + c2 * r2 * (gBest['position'] - particle['position'])
        particle['position'] = particle['position'] + particle['velocity']
        print()
        
    for j in swarm:
        print("Particle ",temp,":",j)
        temp+=1;    
    print("\nGlobal Best Position: ",gBest['position'])
    print()
    
# Result
max_x = gBest['position']
max_f = gBest['fitness']  

print(f"Maximum of f(x) = 1 + 2x - x^2 is found at x = {max_x} with f(x) = {max_f}")