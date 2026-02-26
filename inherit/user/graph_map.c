// graph_map.c
// Per-player graph map state management
// Stores explored rooms and discovered edges in player save data
// Volatile visibility state in tmp_dbase (lost on logout)

// ═══ Explored rooms (persistent, saved) ═══

mapping query_graph_map_explored() {
    mapping m = query("graph_map/explored");
    if (!mapp(m)) return ([]);
    return m;
}

void mark_explored(string room_id) {
    if (!stringp(room_id)) return;
    set("graph_map/explored/" + room_id, 1);
}

int is_explored(string room_id) {
    return query("graph_map/explored/" + room_id) == 1;
}

// ═══ Visible rooms (volatile, recomputed on login/move) ═══

string *query_graph_map_visible() {
    mixed v = query_temp("graph_map/visible");
    if (!arrayp(v)) return ({});
    return v;
}

void set_graph_map_visible(string *rooms) {
    mapping vis_set = ([]);
    set_temp("graph_map/visible", rooms);
    foreach (string rid in rooms) vis_set[rid] = 1;
    set_temp("graph_map/visible_set", vis_set);
}

mapping query_graph_map_visible_set() {
    mixed m = query_temp("graph_map/visible_set");
    if (!mapp(m)) return ([]);
    return m;
}

// ═══ Discovered edges (persistent, for hidden/special exits) ═══

mapping query_graph_map_discovered_edges() {
    mapping m = query("graph_map/discovered_edges");
    if (!mapp(m)) return ([]);
    return m;
}

void mark_discovered_edge(string edge_id) {
    if (!stringp(edge_id)) return;
    set("graph_map/discovered_edges/" + edge_id, 1);
}

// ═══ Known entities (volatile — tracks last-sent entity snapshot for delta) ═══

mapping query_graph_map_known_entities() {
    mixed m = query_temp("graph_map/known_entities");
    if (!mapp(m)) return ([]);
    return m;
}

void set_graph_map_known_entities(mapping entity_map) {
    set_temp("graph_map/known_entities", entity_map);
}

// ═══ Map subscription state (volatile) ═══

int has_graph_map() {
    return query_temp("graph_map/subscribed") == 1;
}

void set_graph_map_subscribed(int v) {
    set_temp("graph_map/subscribed", v);
}
