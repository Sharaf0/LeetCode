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
            if(v === 0 && i !== 0) {
                q.push({node: i, steps: 1}) //zeroDegreesNodes
            }
        })
        let steps = 0
        const visited = {}
        while(q.length > 0) {
            const top = q.shift()
            visited[top.node] = true
            steps = Math.max(steps, top.steps)
            this.adj[top.node].forEach(neighbour => {
                if(--indegrees[neighbour] === 0) {
                    q.push({node: neighbour, steps: top.steps + 1})
                }
            })
        }
        return Object.keys(visited).length !== this.V - 1 ? -1 : steps
    }
}
var minimumSemesters = function(n, relations) {
    const g = new Graph(n + 1)
    
    relations.forEach(([from, to]) => {
        g.addEdge(from, to)
    })
    
    return g.minimumSteps()
};
