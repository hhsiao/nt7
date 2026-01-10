// This program is a part of NT MudLIB
// battelfieldd.c

#include <ansi.h>

#define BATTLE_TIME             900
#define BATTLE_JOIN_TIME        300
#define BATTLE_ROOM             "/maze/jingcheng/"
#define ENTRY_ROOM              "/d/city/wumiao"

string battle_name = HIY"門派"NOR HIR"仇殺"HIR;
object *battle_npc = allocate(0);
mapping battle_player = allocate_mapping(0);
object *total = allocate(0);

int battle_open_flag = 0;
int battle_start_flag = 0;
int battle_time_countdown = 0;
int battle_start_time = 0;

int check_out(object me);
private void restore_status(object me);
void add_damage_score(object me, int score);
void add_killplayer_score(object me, int score);
void add_killnpc_score(object me, int score);
void add_bouns_score(object me, int score);
void calculate_score();

mapping area = ([
    "西城" : ({"/maze/jingcheng/", "dadao36", "dadao35", "dadao34", "dadao33", "dadao32",
        "dadao31", "dadao30", "dadao29", "dadao28", "dadao27", "dadao26", "dadao25",
        "dadao24", "dadao23", "dadao22", "dadao21", "dadao20", "dadao19", "dadao18",
        "dadao17", "dadao16", "dadao15", "dadao14", "dadao13", "dadao12", "dadao11",
        "dadao10", "dadao9", "dadao8", "dadao7"
    }),
    "東城" : ({"/maze/jingcheng/", "dao1", "dao2", "dao3", "dao4", "dao5",
        "dao6", "dao7", "dao8", "dao9", "dao10", "dao11", "dao12",
        "dao13", "dao14", "dao15", "dao16", "dao17", "dao18", "dao19",
        "dao20", "dao21", "dao22", "dao23", "dao24", "dao25", "dao26",
        "dao27", "dao28", "dao29", "dao30"
})
    ]);

mapping menpai1 = ([
    "玄慈大師":   "少林派",
    "宋遠橋":     "武當派",
    "滅絕師太":   "峨嵋派",
    "洪七公":     "丐幫",
    "岳不群":     "華山派",
    "張無忌":     "明教",
    "小龍女":     "古墓派",
    "丘處機":     "全真教"
    ]);

mapping menpai2 = ([
    "丁春秋":     "星宿派",
    "洪安通":     "神龍教",
    "血刀老祖":   "血刀門",
    "歐陽峰":     "歐陽世家",
    "慕容復":     "慕容世家",
    "蘇星河":     "逍遙派",
    "天山童姥":   "靈鷲宮",
    "鳩摩智":     "雪山寺"
    ]);
string *master1 = ({
    "玄慈大師",
    "宋遠橋",
    "滅絕師太",
    "洪七公",
    "岳不群",
    "張無忌",
    "小龍女",
    "丘處機"
});

string *master2 = ({
    "丁春秋",
    "洪安通",
    "血刀老祖",
    "歐陽峰",
    "慕容復",
    "蘇星河",
    "天山童姥",
    "鳩摩智"
});

nosave string fam1;
nosave string fam2;

int clean_up(int inherited) {
    return 1;
}

int in_battle(object me) {
    return battle_start_flag && !undefinedp(battle_player[me->query_id(1)]);
}

int inside_battlefield(object me) {
    string room;
    object env = environment(me);

    if(!objectp(env) )
        return 0;

    room = base_name(env);
    if(!sscanf(room, BATTLE_ROOM "%*s") )
        return 0;

    return 1;
}

int query_battle_time() {
    return battle_time_countdown;

}

int query_player_number(object player) {
    return member_array(player->query_id(1), keys(battle_player)) + 1;
}

void move_to_site(object me) {
    if(objectp(me) && query_temp("chousha/fam", me) )
    {
        if(query_temp("chousha/fam", me) == fam2 )
            me->move("/maze/jingcheng/juyi");
        else if(query_temp("chousha/fam", me) == fam1 )
            me->move("/maze/jingcheng/yingxiong");
    }
    message_vision(YEL"$N一路馬不停蹄，連夜趕到了紫禁城！\n"NOR, me);
}

int is_battle_open() {
    return battle_open_flag;
}

int is_battle_start() {
    return battle_start_flag;
}

void init_player(object me) {
    tell_object(me, HIY "你眼前忽然一花...\n" NOR);
    me->set_override("unconcious", (: call_other, __FILE__, "check_out": ));
    me->set_override("die", (: call_other, __FILE__, "check_out": ));
    me->set_override("quit", (: call_other, __FILE__, "check_quit": ));
    set_temp("override/receive_damage", (:call_other, __FILE__, "receive_damage": ), me);
    set_temp("backup/killer", me->query_killer(), me);
    set_temp("backup/want", me->query_want(), me);
    set_temp("in_pkd", 1, me);

    //tell_object(me, HIR "你被傳送到戰場中...。\n");
    set("backup/condition", me->query_condition(), me);
    me->clear_condition();

    if(!arrayp(total) )
        total = ({ me });
    else
        if(member_array(me, total) == -1 )
        total += ({ me });

    if(query_temp("chousha/fam", me)==fam2 )
    {
        set_temp("apply/short",
            ({ HIW + fam1 + "同道"NOR + HIG"   江湖義士   "NOR + query("name", me) + "("+query("id", me) + ")" }), me);
    }
    else if(query_temp("chousha/fam", me)==fam1 )
    {
        set_temp("apply/short",
            ({ CYN + fam2 + "助拳"NOR + HIG"   江湖豪客   "NOR + query("name", me) + "("+query("id", me) + ")" }), me);
    }
    move_to_site(me);
}

// 參與戰爭
void join_battle(object me) {
    mapping cnd;
    string id = me->query_id(1);
    string temp;
    int exp, exp_rate;

    if(me->is_busy() )
        return tell_object(me, BUSY_MESSAGE);

    if(me->is_fighting() )
        return tell_object(me, "你目前正在戰鬥中，還是先處理目前的對手再說吧。\n");

    if (me->is_in_prison())
        return tell_object(me, "你正在做牢呢，你想幹什麼？！\n");

    if (me->is_ghost())
        return tell_object(me, "你還是等還陽後再說吧！\n");

    if(!battle_open_flag )
        return tell_object(me, battle_name + "目前無法報名。\n");

    if(query("combat_exp", me)<1000000 )
        return tell_object(me, CYN"憑你現在這點本事，不相干的事還是不要多管的好！\n"NOR);

    if(mapp(cnd = me->query_condition()) && sizeof(cnd))
    {
        if(!undefinedp(cnd["hunger"]) )
            return tell_object(me, "你還是先找點吃的東西再說吧。\n");

        if(!undefinedp(cnd["killer"]) )
            return tell_object(me, "官府正在通緝你，你還敢在這兒拋頭露面？\n");

        if(!undefinedp(cnd["bandage"]) )
            return tell_object(me, "你還是等包紮的傷口止住了血再說吧！\n");

        if(!undefinedp(cnd["putizi_drug"]) )
            return tell_object(me, "你剛服完菩提子不久，好好運功夫吸納吧！\n");

        if(!undefinedp(cnd["vote_clear"]) )
            return tell_object(me, "現在玩家正在對你進行表決，你別到處亂走。\n");

        return tell_object(me, "你現在狀態不佳，還是別進去了。\n");
    }

    if(!undefinedp(battle_player[id]) )
    {
        if(!battle_start_flag )
            return tell_object(me, "你已經報名參與這次的戰爭，請耐心等候出征。\n");

        if(inside_battlefield(me) )
            return tell_object(me, "你已經在戰場中，快點殺敵吧。\n");

        if(!query_temp("chousha/fam", me) )
            return tell_object(me, "你還是等下一場門派仇殺吧。\n");

        if(!query_temp("chousha_rejoin", me) )
            return tell_object(me, "你必須使用仇殺勳章方可重新進入戰場。\n");

        delete_temp("chousha_rejoin", me);
        init_player(me);
        return;
    }

    exp = query("combat_exp", me);
    temp = read_file("/quest/quest4/exp_rate", 1, 1);
    exp_rate = atoi(temp);
    if(!wizardp(me) && (exp_rate*exp_rate / 4) < exp / 100000 )
    {
        do{
            exp_rate++;
        }       while((exp_rate*exp_rate / 4) < exp / 100000 );

        temp = sprintf("%d", exp_rate);
        write_file("/quest/quest4/exp_rate", temp, 1);
    }

    if(query_temp("chousha/fam", me) )
    {
        CHANNEL_D->channel_broadcast("mess", query("name", me) + "報名加入門派仇殺對付門派"+query_temp("chousha/fam", me) + "！\n");

    } else
    if(query("shen", me) >= 200000 || (query("shen", me) > -200000 && random(2)) )
    {
        set_temp("chousha/fam", fam2, me);
        CHANNEL_D->channel_broadcast("mess", query("name", me) + "報名加入門派仇殺對付門派"+fam2 + "！\n");
    } else
    {
        set_temp("chousha/fam", fam1, me);
        CHANNEL_D->channel_broadcast("mess", query("name", me) + "報名加入門派仇殺對付門派"+fam1 + "！\n");
    }

    battle_player[id] = allocate_mapping(0);
    battle_player[id]["jointime"] = time();

    CHANNEL_D->channel_broadcast("war", "目前共有 "+sizeof(battle_player)+
        " 位玩家報名參與「"+battle_name + "」");

    if(battle_start_flag )
    {
        init_player(me);
    }
}

// 取消參與戰爭
void cancel_battle(object me) {
    string id = me->query_id(1);

    if(undefinedp(battle_player[id]) )
        return tell_object(me, "你原本就沒有報名參與這次的戰爭。\n");

    if(battle_start_flag )
        return tell_object(me, "這次的戰爭已經開始，你無法取消，可用quit指令逃離戰場。\n");

    map_delete(battle_player, id);

    addn("honors", -100, me);
    if(query("honors", me) < 0 );
    set("honors", 0, me);

    CHANNEL_D->channel_broadcast("war", "目前共有 "+sizeof(battle_player)+
        " 位玩家報名參與「"+battle_name + "」");
}

int check_quit(object me) {
    CHANNEL_D->channel_broadcast("war", "玩家" + me->name(1) + "在「"+battle_name + "」中臨陣脫逃，溜走了。"NOR);
    restore_status(me);

    addn("honors", -500, me);
    if(query("honors", me) < 0 );
    set("honors", 0, me);

    if(arrayp(total) )
        total -= ({ me });

    tell_object(me, HIC "你一口氣逃出了戰場，來到揚州中央廣場。\n" NOR);

    // continue run quit function
    me->move("/d/city/guangchang");
    message("vision", "只見" + me->name() + "慌里慌張的跑了過來。\n",
        environment(me), ({ me }));

    return 1;
}

varargs int receive_damage(object me, string type, int damage, object who)
{
    if(!who ) who = me->query_last_damage_from();
    if(!who ) return 0;

    if(type != "qi" || damage < 1 ) return 0;

    if(userp(me) )
        add_damage_score(who, damage);
    else
        add_damage_score(who, damage / 3);

    return 0;
}

// check all the players who join the competition
private void auto_check() {
    object ob;
    //      string msg;
    string room;
    object *lost;
    int i;

    lost = ({ });
    for (i = 0; i < sizeof(total); i++)
    {
        if(!objectp(total[i]) )
            continue;
        room = base_name(environment(total[i]));
        if(!sscanf(room, BATTLE_ROOM "%*s"))
        {
            // not in pk room
            restore_status(total[i]);
            total[i] = 0;   // 保留報名參加戰場的記錄
            continue;
        }
        if(query("qi", total[i])<1 || query("jing", total[i])<1 )
            lost += ({ total[i] });
    }

    // kickout the players who lost competition
    foreach (ob in lost)
        check_out(ob);

    total -= ({ 0 });
}

int check_out(object me) {
    object ob;
    mapping my;
    string msg;
    string room;

    room = base_name(environment(me));
    if(!sscanf(room, BATTLE_ROOM "%*s") )
    {
        // not in pk room
        total -= ({ me });
        return 0;
    }

    my = me->query_entire_dbase();
    my["eff_qi"] = my["max_qi"];
    my["eff_jing"] = my["max_jing"];
    my["qi"] = 1;
    my["jing"] = 1;

    tell_object(me, HIR "\n你覺得眼前一陣模糊...這下完了！\n" NOR);
    if(ob = me->query_last_damage_from() )
    {
        msg = me->name(1) + "慘遭" + ob->name(1) + "的毒手，被無情ＰＫ。\n";
        if(userp(ob) )
        {
            if(userp(me) )
            {
                if(!query("doing", me) && query_ip_number(ob) != query_ip_number(me) )
                    if(query_temp("chousha/fam", me) != query_temp("chousha/fam", ob) )
                    add_killplayer_score(ob, 1);
            }
            else
            {
                if(query_temp("chousha/fam", me) != query_temp("chousha/fam", ob) )
                    add_killnpc_score(ob, 1);
                return 0;
            }
        }
    } else
    msg = me->name(1) + "運氣不佳，本領有限、已經慘遭ＰＫ。\n";

    if(!userp(me) ) return 0;

    message("vision", msg, environment(me), ({ me }));

    restore_status(me);
    total -= ({ me });
    me->move(ENTRY_ROOM);
    message("vision", "一個黑影倏的竄了出來，隨即就是“啪”的"
        "一聲，就見" + me->name() + "摔倒了地上，一副半死不"
        "活的樣子。\n", environment(me), ({ me }));
    tell_object(me, "半昏半迷中，你覺得被人拎了起來，又"
        "重重的摔倒了地上。\n");

    if(!living(me) )
        me->revive();

    return 1;
}

int place_room(string site_name, object ob) {
    string *location, site_file;
    int size;

    location = area[site_name];
    size = sizeof(location);
    site_file = location[0] + location[random(size - 1) + 1];
    set("area", site_name, ob);
    set("place_name", site_file, ob);
    set_temp("override/receive_damage", (:call_other, __FILE__, "receive_damage": ), ob);
    ob->move(site_file);
    tell_room(site_file, HIY + ob->query_idname() + HIY"突然從角落竄了出來！\n"NOR);
    return 1;
}

void add_npc(int n) {
    int i;
    object killer1, killer2;

    for(i = 0; i<n; i++ )
    {
        if(sizeof(children("/quest/quest4/killer1.c")) < 80 )
        {
            killer1 = new("/quest/quest4/killer1");
            place_room("西城", killer1);
            killer1->start_escape(900);
            killer1->set_override("die", (: call_other, __FILE__, "check_out": ));
            set_temp("battle_npc", 1, killer1);
            battle_npc += ({ killer1 });
        }
        if(sizeof(children("/quest/quest4/killer2.c")) < 80 )
        {
            killer2 = new("/quest/quest4/killer2");
            place_room("東城", killer2);
            killer2->start_escape(900);
            killer2->set_override("die", (: call_other, __FILE__, "check_out": ));
            set_temp("battle_npc", 1, killer2);
            battle_npc += ({ killer2 });
        }
    }
}

// 啟動戰爭
void start_battle() {
    int n;
    object player;
    object* unavailable_players = allocate(0);

    if(sizeof(battle_player) < 2 )
    {
        set_heart_beat(0);
        total = allocate(0);
        battle_player = allocate_mapping(0);
        battle_open_flag = 0;
        battle_start_time = 0;
        CHANNEL_D->channel_broadcast("war", "報名參與「"+battle_name + "」戰役的玩家不足 2 人，取消本次戰役。");
        return;
    }

    n = sizeof(battle_player)*15;
    if(n > 100 ) n = 100;
    add_npc(n);

    CHANNEL_D->channel_broadcast("mess", HIR + fam1 + HIC"與"+HIR + fam2 + HIC"兩大門派積怨已久，此刻正在紫金城正相互仇殺。"NOR);
    CHANNEL_D->channel_broadcast("war", "「"+battle_name + "」開始出征！共計 "+sizeof(battle_player)+
        " 位玩家參與「"+battle_name + "」，計時 "+(BATTLE_TIME / 60) + " 分鐘結束");


    foreach(string id, mapping data in battle_player)
    {
        reset_eval_cost();

        if(!objectp(player = find_player(id)) )
            continue;

        if(query_temp("running", player) )
        {
            tell(player, pnoun(2, player) + "正在飛行中，無法加入戰場。\n");
            unavailable_players |= ({ player });
            continue;
        }

        init_player(player);
        //tell_object(player, "\a「"+battle_name+"」開始，你被傳送到戰場中...\n");
    }

    foreach(player in unavailable_players)
        cancel_battle(player);

    battle_start_flag = 1;
    battle_time_countdown = BATTLE_TIME;
}

// 開始接受報名 TIME_D 調用
void start_join() {
    int i, j, k;
    object *ulist;

    i = random(sizeof(master1));
    j = random(sizeof(master2));
    ulist = users();
    k = sizeof(ulist);

    fam1 = menpai1[master1[i]];
    fam2 = menpai2[master2[j]];
    while(k-- )
    {
        if(!environment(ulist[k]) ) continue;
        delete_temp("chousha", ulist[k]);

        if(ulist[k]->query_family() == fam1 )
            set_temp("chousha/fam", fam2, ulist[k]);
        else if(ulist[k]->query_family() == fam2 )
            set_temp("chousha/fam", fam1, ulist[k]);
    }

    write_file("/quest/quest4/fam1", fam1, 1);
    write_file("/quest/quest4/fam2", fam2, 1);

    CHANNEL_D->channel_broadcast("mess", master1[i] + "："+fam1 + "門下弟子聽令，命你們在半個時辰內將"+fam2 + "徹底擊潰，以匡武林正義！");
    CHANNEL_D->channel_broadcast("mess", master2[j] + "："+fam2 + "弟子聽令，命你們在半個時辰內將"+fam1 + "徹底蕩平，讓他們嚐嚐我們的厲害！");
    CHANNEL_D->channel_broadcast("war", HIY"榮耀"NOR YEL"之戰"HIR"發出戰爭集結，即將在 "+(BATTLE_JOIN_TIME / 60)+
        " 分鐘後發動「"+battle_name + "」，請使用 chousha join 指令加入戰役。");
    total = allocate(0);
    battle_npc = allocate(0);
    battle_player = allocate_mapping(0);
    battle_open_flag = 1;

    battle_start_time = BATTLE_JOIN_TIME;

    set_heart_beat(1);

    //tell_object(users(), "\a");
}

int get_player_score(string id) {
    if(undefinedp(battle_player[id]) ) return 0;

    return battle_player[id]["killplayer"]*100 + battle_player[id]["killnpc"]*30 + (battle_player[id]["damage"] / 500000>1500?1500:battle_player[id]["damage"] / 500000) + battle_player[id]["bonus"];
}

string *get_sorted_players()
{
    return sort_array(keys(battle_player), (: get_player_score($2) - get_player_score($1) :));
}

void add_damage_score(object me, int score) {
    string id = me->query_id(1);

    if(undefinedp(battle_player[id]) )
        return;

    battle_player[id]["damage"] += score;
}

void add_killnpc_score(object me, int score) {
    string id = me->query_id(1);

    if(undefinedp(battle_player[id]) )
        return;

    battle_player[id]["killnpc"] += score;
}

void add_killplayer_score(object me, int score) {
    string id = me->query_id(1);

    if(undefinedp(battle_player[id]) )
        return;

    battle_player[id]["killplayer"] += score;

    return;
}

void add_dead_score(object me, int score) {
    string id = me->query_id(1);
    string *sorted_players = get_sorted_players();

    if(undefinedp(battle_player[id]) )
        return;

    if(sizeof(sorted_players) > 0 && sorted_players[0] == id )

    battle_player[id]["bonus"] -= 40;

    battle_player[id]["dead"] += score;
}


void add_bonus_score(object me, int score) {
    string id = me->query_id(1);

    if(undefinedp(battle_player[id]) )

    return;

    battle_player[id]["bonus"] += score;
    //addn("honors", score, me);

    return;
}

void stop_battle() {
    object player;
    object *ulist;
    int k;

    ulist = users();
    k = sizeof(ulist);

    while(k-- )
    {
        if(!environment(ulist[k]) ) continue;
        if(query_temp("chousha", ulist[k]) )
        {
            delete_temp("chousha", ulist[k]);
        }
    }

    CHANNEL_D->channel_broadcast("mess", "歷時半月的"+fam1 + "與"+fam2 + "之間的仇殺終於結束了，雙方皆死傷無數！");

    set_heart_beat(0);

    foreach(string id in keys(battle_player))
    {
        if(!objectp(player = find_player(id)) )
            continue;

        //player->remove_all_killer();
        player->remove_all_enemy(1);
        tell_object(player, BLINK"忽然你心中生起一股厭倦的感覺，"
            "開始疑惑的這樣的江湖仇殺有何意義，\n"
            "你看著自己沾滿鮮血的手，開始不斷地問自己為什麼？為什麼？.....\n"NOR);
    }

    foreach(object npc in battle_npc )
    {
        if(!objectp(npc) )
            continue;

        destruct(npc);
    }

    fam1 = fam2 = "";
    battle_open_flag = 0;
    battle_start_flag = 0;
    battle_time_countdown = 0;

    call_out((: calculate_score :), 5);

    CHANNEL_D->channel_broadcast("war", WHT"————————————————————————————————"NOR);
    CHANNEL_D->channel_broadcast("war", "「"+battle_name + HIR"」終於漸漸平息..."NOR);
    CHANNEL_D->channel_broadcast("war", "「"+battle_name + HIR"」正在統計戰績..."NOR);
    CHANNEL_D->channel_broadcast("war", WHT"————————————————————————————————"NOR);
}

void calculate_score() {
    int score;
    int rank;
    string family;
    object player;
    //      string file;
    object insigne;
    int insigne_count;
    string *sorted_players = get_sorted_players();
    int lv1, lv2, lv3, lv4;
    int players_count = sizeof(sorted_players);

    map_delete(battle_player, 0);

    CHANNEL_D->channel_broadcast("war", WHT"————————————————————————————————"NOR);

    lv2 = players_count / 4;
    if(lv2 < lv1 + 2 ) lv2 = lv1 + 2;

    lv3 = to_int(players_count / 1.5);
    if(lv3 < lv2 + 3 ) lv3 = lv2 + 3;

    lv4 = to_int(players_count / 1.2);
    if(lv4 < lv3 + 5 ) lv4 = lv3 + 5;

    rank = 0;
    foreach(string id in sorted_players)
    {
        if(!objectp(player = find_player(id)) )
            continue;

        family = player->query_family();
        score = get_player_score(id);

        CHANNEL_D->channel_broadcast("war", (++rank) + "."+(family||"普通百姓") + "的"+player->query_idname() + HIR"共擊殺 "+battle_player[id]["killplayer"] + " 位玩家、"+battle_player[id]["killnpc"] + " 個NPC，總計造成敵人 "+NUMBER_D->number_symbol(battle_player[id]["damage"]) + " 點傷害，戰績結算為 "+NUMBER_D->number_symbol(score) + (battle_player[id]["bonus"]>=0 ? "("NOR CYN"+"HIC + battle_player[id]["bonus"] + HIR")":"("NOR RED"-"HIR + (-battle_player[id]["bonus"]) + HIR")") + " 分");

        addn("battle/score", score, player);
        addn("honors", score, player);

        if(score > 5000 ) score = 5000;
        GIFT_D->delay_battle_bonus(player, ([ "exp": score*2000, "pot": score*600, "mar": score*100, "gongxian": score*10, "score": score ]));

        if(score < 25 || battle_player[id]["jointime"] > time() - 600 ) continue;

        insigne_count = 0;

        if(rank <= lv1 )
        {
            insigne_count = 8;
        }
        else if(rank <= lv2 )
        {
            insigne_count = 7;
        }
        else if(rank <= lv3 )
        {
            insigne_count = 7;
        }
        else if(rank <= lv4 )
        {
            insigne_count = 6;
        }
        else
        {
            insigne_count = 2;
        }

        if(insigne_count > 0 )
        {
            insigne = new("/clone/battle/chousha_insigne");
            insigne->set_amount(insigne_count);
            tell_object(player, "你獲得 "+insigne_count + " 枚"+insigne->name(1) + "。\n");
            insigne->move(player, 1);
        }
    }

    CHANNEL_D->channel_broadcast("war", WHT"————————————————————————————————"NOR);

    //foreach(string id in keys(battle_player))
    foreach(player in total)
    {
        //if( !objectp(player = find_player(id)) )
        if(!objectp(player) )
            continue;

        restore_status(player);
        player->move(ENTRY_ROOM);

        tell_object(player, "「"+battle_name + "」結束，你被傳離戰場...\n");

    }

    total = allocate(0);
    battle_npc = allocate(0);
    battle_player = allocate_mapping(0);
}


mapping query_battle_player() {
    return battle_player;
}

varargs void remove(mixed euid) {
    if(sizeof(battle_player) )
    {
        object player;

        CHANNEL_D->channel_broadcast("war", "系統更新，重置「"+battle_name + HIR"」"NOR);

        foreach(string id in keys(battle_player))
        {
            if(!objectp(player = find_player(id)) )
                continue;

            restore_status(player);
            player->move(ENTRY_ROOM);
        }
    }

    if(sizeof(battle_npc) )
    {
        foreach(object npc in battle_npc)
        {
            if(!objectp(npc) )
                continue;

            destruct(npc);
        }
    }
    fam1 = fam2 = "";
}

void heart_beat() {
    //      mapping buff,data;
    string *directions = ({ "north", "south", "east", "west" });
    //      object where;
    //      int i;

    if(battle_start_time > 0 )
    {
        switch(--battle_start_time)
        {
        case 0:
            start_battle();
            break;
        case 60:
        case 120:
        case 180:
        case 240:
            CHANNEL_D->channel_broadcast("mess", HIB"據可靠消息，會有兩大門派在不久以後大火拼。");
            CHANNEL_D->channel_broadcast("war", HIY"榮耀"NOR YEL"之戰"HIR"發出戰爭集結，即將在 "+(battle_start_time / 60)+
            " 分鐘後發動「門派仇殺」，請使用chousha join加入戰役。");
            break;
        case 270:
            CHANNEL_D->channel_broadcast("mess", HIR "據說江湖中某兩大門派為解宿怨，半個時辰內要以武力解決。");
            CHANNEL_D->channel_broadcast("war", HIY"榮耀"NOR YEL"之戰"HIR"發出戰爭集結，即將在 "+(battle_start_time / 60)+
            " 分鐘後發動「門派仇殺」，請使用chousha join加入戰役。");
            break;
        }

        return;
    }

    if(!battle_start_flag )
        return;

    if(--battle_time_countdown <= 0 )
    {
        stop_battle();
        return;
    }

    auto_check();

    if(!(battle_time_countdown % 120) )
    {
        add_npc(sizeof(battle_player)*8);
    }

    if(battle_time_countdown == 60 || battle_time_countdown == 180 )
        CHANNEL_D->channel_broadcast("war", "「門派仇殺」即將在 "+(battle_time_countdown / 60) + " 分鐘後結束...");

    /*
     * 因為被利用這個buff吸內力，故而關閉
     * if( !(battle_time_countdown%60) )
     * {
     * object player;
     * string* sorted_players = get_sorted_players();
     * int size = sizeof(sorted_players);

     * for( i=size*2/3;i<size;++i )
     * {
     * if( objectp(player = find_player(sorted_players[i])) )
     * {
     * if( !inside_battlefield(player) ) continue;

     * if( BUFF_D->check_buff(player, "chousha_bonus") ) continue;

     * //tell_object(player, pnoun(2, player)+"目前的戰績落後，獲得額外能力加持。\n");

     * if( i > size*4/5 )
     * {
     * data = ([
     * "attack": player->query_skill("force",1),
     * "defense":player->query_skill("dodge",1),
     * "add_skill": player->query_skill("parry",1)/10,
     * ]);
     * } else
     * {
     * data = ([
     * "attack": player->query_skill("force"),
     * "defense":player->query_skill("dodge"),
     * "add_skill": player->query_skill("parry")/10,
     * ]);
     * }

     * buff = ([
     * "caster":player,
     * "target":player,
     * "type":"chousha_bonus",
     * "attr":"bless",
     * "name":"戰場榮耀·能力加持",
     * "time":battle_time_countdown,
     * "buff_data":data,
     * "buff_msg":HIY"$N目前的戰績落後，獲得額外能力加持。\n"NOR,
     * "disa_msg":"你的戰場榮耀·能力加持逐漸消失。\n",
     * ]);
     * BUFF_D->buffup(buff);
     * }
     * }
     * }
     */
    foreach(object npc in battle_npc)
    {
        if(!objectp(npc) )
            continue;

        if(!random(10) )
        {

            if(npc->is_fighting() )
                continue;

            if(sizeof(directions) )
                npc->do_command("go "+directions[random(sizeof(directions))]);
        }
    }

    battle_npc -= ({ 0 });
}

private void restore_status(object me) {
    mapping my, cnd;
    string *ks;
    int i;

    me->delete_override("unconcious");
    me->delete_override("die");
    me->delete_override("quit");
    delete_temp("override/receive_damage", me);
    me->remove_all_enemy(1);
    me->remove_all_killer();
    me->clear_condition();
    me->stop_busy();
    me->receive_damage("qi", 0);
    me->apply_killer(query_temp("backup/killer", me));
    me->apply_want(query_temp("backup/want", me));

    cnd = query("backup/condition", me);
    delete("backup/condition", me);
    delete_temp("block_msg/all", me);
    delete_temp("in_pkd", me);
    delete_temp("apply/short", me);

    if(!mapp(cnd) ) return;
    ks = keys(cnd);
    for(i = 0; i < sizeof(ks); i++ )
        me->apply_condition(ks[i], cnd[ks[i]]);

    my = me->query_entire_dbase();
    if(my["qi"] < 1 )       my["qi"] = 1;
    if(my["eff_qi"] < 1 )   my["eff_qi"] = 1;
    if(my["jing"] < 1 )     my["jing"] = 1;
    if(my["eff_jing"] < 1 ) my["eff_jing"] = 1;
}

void create() {
    seteuid(ROOT_UID);
}

string query_name() {
    return "戰場系統(BATTLEFIELD_D)";
}
