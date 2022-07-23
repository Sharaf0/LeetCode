const Trie = function() {
    this.nodes = {}
    this.isEnd = false
};

Trie.prototype.insert = function(word) {
    let ref = this
    let len = word.length
    word.split('').forEach((c, index) => {
        if(!ref.nodes[c])
            ref.nodes[c] = new Trie()
        ref = ref.nodes[c]
        if(index === len - 1)
            ref.isEnd = true
    })
};

const traverse = (trie, graph) => {
    const children = Object.keys(trie.nodes) || []
    const chars = children
    for(let i = 0; i < chars.length; i ++) {
        if(!graph[chars[i]])
            graph[chars[i]] = new Set()
        for(let j = i + 1; j < chars.length; j ++) {
            graph[chars[i]].add(chars[j])
        }
    }
    for(let i = 0; i < chars.length; i ++) {
        traverse(trie.nodes[chars[i]], graph)
    }
}

const topologicalSortHelper = (node, explored, s, graph) => {
    explored.add(node);
    const edges = graph[node]
    edges.forEach(n => {
      if (!explored.has(n)) {
         topologicalSortHelper(n, explored, s, graph);
      }
    });
    s.push(node);
}

const topologicalSort = (graph) => {
    const nodes = Object.keys(graph)
    let s = []
    let explored = new Set()
    nodes.forEach(node => {
      if (!explored.has(node)) {
         topologicalSortHelper(node, explored, s, graph);
      }
    });
    s.reverse()
    return s
}

/**
 * @param {string[]} words
 * @return {string}
 */
var alienOrder = function(words) {
    for(let i = 1; i < words.length; i ++) {
        for(let j = 0; j < i; j ++) {
            if(words[i] === words[j].substring(0, words[i].length) && words[j].length > words[i].length)
                return ""
        }
    }
    const trie = new Trie()
    words.forEach(word => trie.insert(word))
    const graph = {}
    traverse(trie, graph)
    const ans = topologicalSort(graph)
    const originalWords = [...words]
    words.sort((w1, w2) => {
        const wc1 = w1.split("")
        const wc2 = w2.split("")
        const mn = Math.min(wc1.length, wc2.length)
        for(let i = 0; i < mn; i ++) {
            const w1i = ans.indexOf(wc1[i])
            const w2i = ans.indexOf(wc2[i])
            if(w1i === w2i) continue
            return (w1i < w2i) ? -1 : 1
        }
        return 1
    })
    if(JSON.stringify(originalWords)==JSON.stringify(words))
        return ans.join('')
    return ""
};
