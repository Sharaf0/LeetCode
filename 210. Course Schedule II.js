class Graph {
    constructor(v) {
        this.V = v

        this.adj = new Array(this.V)
        for (let i = 0; i < this.V; i += 1) {
            this.adj[i] = new Array()
        }
        this.inEdges = new Array(v).fill(0)
    }

    addEdge(v, w) {
        this.adj[v].push(w)
        this.inEdges[w] ++
    }
    
    minimumSteps() {
        const indegrees = [...this.inEdges]
        const q = []
        indegrees.forEach((v, i) => {
            if(v === 0) {
                q.push({node: i, steps: 1}) //zeroDegreesNodes
            }
        })
        let maxPath = []
        const visited = {}
        while(q.length > 0) {
            const {node, steps} = q.shift()
            maxPath.push(node)
            visited[node] = true
            this.adj[node].forEach(neighbour => {
                if(--indegrees[neighbour] === 0) {
                    q.push({node: neighbour, steps: steps + 1})
                }
            })
        }
        maxPath.reverse()
        return Object.keys(visited).length !== this.V ? [] : maxPath
    }
}
var findOrder = function(n, relations) {
    const g = new Graph(n)
    
    relations.forEach(([from, to]) => {
        g.addEdge(from, to)
    })
    
    return g.minimumSteps()
};
