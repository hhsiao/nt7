// This program is a part of NITAN MudLIB
// redl 2013/9
#include <ansi.h>
#include <room.h>

inherit ROOM;

#define FILEPATH "/u/redl/teleport/"

int clean_up(int inherited) { return 1;}

mapping *sign = ({
    ([
        "file": FILEPATH "tower",
        "loop": FILEPATH,   //持續支付時，檢查房間範圍
        "val": 50000
    ]),
    ([
        "file": FILEPATH "qiulao",
        "loop": FILEPATH,
        "val": 10000
    ]),
    ([
        "file": FILEPATH "tiangong",
        "loop": FILEPATH,
        "val": 30000
    ]),
    ([
        "file": FILEPATH "shike",
        "loop": FILEPATH,
        "val": 650000
    ]),
    ([
        "file": FILEPATH "baodu",
        "val": 90000000
    ]),
    ([
        "file": FILEPATH "lankeshan",
        "val": 1000000                                                     ]),
    ([
        "file": FILEPATH "huaguo",
        "loop": FILEPATH,
        "val": 10000000
    ]),
    ([
        "file": FILEPATH "18niuren",
        "loop": FILEPATH,
        "val": 10000000
    ]),
    ([
        "file": FILEPATH "ailao",
        "val": 1000000000
    ]),
    ([
        "file": FILEPATH "buzhoushanjiao",
        "val": 10000
    ]),
    ([
        "file": "/d/pk/entry",
        "val": 500000
    ])
});


string look_kong(object me) {
    string msg;
    int j = 0;
    int i = -1;

    msg = CYN
    "孔旁邊有幾行字：\n"
    "  此陣名曰『巧雲飛星陣』，它可以帶你穿梭到神秘的地方。\n"
    "  但需要花費財物來維持它的能量，指令：<put 數量 貨幣>\n" NOR;
    while(i++<sizeof(sign) - 1){
        if (sign[i]["short"]) {
            msg += sprintf(" %-28s", sign[i]["exit"] + ":" + sign[i]["short"] + "("+ chinese_number(sign[i]["val"] / 10000) + "金·" + (sign[i]["loop"]? "維持":"進入") + ")");
            j ++;
            if (j>1) {
                msg += "\n";
                j = 0;
            }
        }
    }
    if (j!=0) msg += "\n";

    return msg;
}

void create_exit() {
    object ob;
    int i = -1;
    int k = 1;

    while(i++<sizeof(sign) - 1){
        if (sign[i]["file"]) {
            ob = load_object(sign[i]["file"]);
            if (objectp(ob)){
                sign[i] += (["short": query("short", ob)]);
                sign[i] += (["exit": sprintf("%d", k)]);
                k++;
                set("exits/" + sign[i]["exit"], sign[i]["file"]);
            }
        }
    }
}

int do_put(string arg) {
    object me;
    object ob;
    object *inv;
    string units;
    int amount;
    int value;
    int max_count;
    int i;

    if(!arg )
    {
        write(NOR "你要把什麼投進去？\n" NOR);
        return 1;
    }

    me = this_player();

    if ((time() - query_temp("teleportroom/put_time", me)) < 6)
    {
        write(NOR "你這樣反反覆覆算什麼，等一會兒再投吧。\n" NOR);
        return 1;
    }

    if(!interactive(me) || !playerp(me) || me->is_busy()) {
        write(NOR "你正忙著呢。\n" NOR);
        return 1;
    }

    if(sscanf(arg, "%d %s", amount, arg) != 2 )
    // not indicate the amount of the goods
    amount = 1;

    if(amount < 1 )
    {
        write(NOR "你到底想投多少呢？\n" NOR);
        return 1;
    }

    ob = present(arg, me);
    if(!ob )
    {
        inv = all_inventory(me);
        for(i = 0; i < sizeof(inv); i++ )
        {
            if(filter_color(inv[i]->name(1)) == arg )
            {
                ob = inv[i];
                break;
            }
        }
    }

    if (!objectp(ob) )
    {
        write("你身上沒有這種東西啊！\n");
        return 1;
    }

    if (!query("money_id", ob))
    {
        write(NOR "在這裡只能投錢哦！\n" NOR);
        return 1;
    }

    max_count = ob->query_amount();
    if(!max_count )
    {
        // not combined object
        if(amount > 1 )
        {
            write(NOR + "這" + ob->name() + NOR + "是什麼東西？\n" + NOR);
            return 1;
        }
        max_count = 1;
    } else
    {
        // is combined object
        if(amount > max_count )
        {
            write(NOR + "你身上沒有這麼多" + ob->name() + NOR + "。\n" + NOR);
            return 1;
        }
    }

    value = query("base_value", ob) * amount;

    if(value < 1000000 )
    {
        write(NOR "你連一百兩黃金都拿不出來？這也太寒酸了點吧...\n" NOR);
        return 1;
    }

    set_temp("teleportroom/put_value", value, me);
    set_temp("teleportroom/put_time", time(), me);

    units = query("base_unit", ob);
    if (!units) units = query("unit", ob);
    if (!units) units = "個";

    message_vision(append_color(CYN + "$N掏出" + chinese_number(amount) + units + ob->name() + CYN + "走過去，機關人迎上前拿過，轉身往孔裡投了些能量石。\n" + NOR, CYN), me);

    if(max_count == amount ) {
        destruct(ob);
    }
    else
    {
        ob->add_amount(-amount);
    }

    return 1;
}


int do_look(string arg) {
    object me = this_player();
    //if ( arg && sscanf(arg, "%*d") ) {
    if (arg && arg!="south" && arg!="southeast" && query("exits/" + arg) && wiz_level(me) < 5 ) {
        tell_object(me, NOR "你凝聚目力望過去，卻只見渾沌的玄奧氣象。\n" NOR);
        return -1;
    }
    return 0;
}

int init() {
    object me = this_player();
    if (!interactive(me) || !playerp(me)) return 1;
    add_action("do_look", "look");
    add_action("do_put", "put");
    if (wiz_level(me) > 5) {
        add_action("do_stop", "stop");
    }
    return 1;
}

int do_tell_val(object me) {
    tell_object(me, sprintf(HIG "巧雲飛星陣：你儲蓄的能量還餘(%d)點。\n\n" NOR, query_temp("teleportroom/put_value", me) / 10000));
    return 1;
}

int do_tell_back(object me) {
    //tell_object(me, sprintf(HIG "\n天邊一股虛弱的能量束縛住了你..\n\n" NOR));
    message_vision(append_color(NOR + YEL + "\n天邊一股虛弱的能量束縛住了$N..\n\n" + NOR, YEL), me);
    me->move(this_object());
    //tell_object(me, sprintf(HIG "天旋地轉中，你頭暈目眩地被拉回了法陣。\n\n" NOR));
    message_vision(append_color(NOR + YEL + "天旋地轉中，$N頭暈目眩地被拉回了法陣。\n\n" + NOR, YEL), me);
    return 1;
}

int is_area(mapping my) {
    object me = my["ob"];

    if (!objectp(me) ||
        !playerp(me) ||
        !interactive(me) ||
        !environment(me) ||
        !objectp(environment(me)) ||
        base_name(environment(me))==base_name(this_object()) ) return 0;
    if (!sscanf(base_name(environment(me)), sprintf("%s", my["path"]) + "%*s") ) return 0;

    if (query_temp("teleportroom/put_value", me) < my["cost"] && time() - my["time"] > 59) {
        do_tell_back(me);
        return -1;
    }

    if (time() - my["time"] > 59) {
        addn_temp("teleportroom/put_value", -my["cost"], me);
        do_tell_val(me);
        return 1;
    }

    return 2;
}

int check_teleroom() {
    mapping usrs;
    string *ks;
    int count;

    remove_call_out("check_teleroom");
    usrs = query("tele_users");
    if (sizeof(usrs)) {
        ks = keys(usrs);
        for(count = sizeof(ks); count > 0; count--)
        {
            //tell_object(find_player("redl"), sprintf("%s\n", ks[count-1]));
            switch (is_area(query("tele_users/" + ks[count - 1])) ) {
            case -1:
            case 0:
                delete("tele_users/" + ks[count - 1]);
                break;
            case 1:
                set("tele_users/" + ks[count - 1] + "/time", time());
                break;
            default :
                break;
            }
        }
    }

    call_out("check_teleroom", 10);
}

int do_stop(string arg)   //先清場，再改編
{
    mapping usrs;
    string *ks;
    int count;
    object ob;
    object me = this_player();

    if (query("do_stop")) {
        delete("do_stop");
        check_teleroom();
        tell_object(me, YEL + "維修完畢，開放使用！\n" + NOR);
    } else {
        set("do_stop", 1);

        remove_call_out("check_teleroom");
        usrs = query("tele_users");
        if (sizeof(usrs)) {
            ks = keys(usrs);
            for(count = sizeof(ks); count > 0; count--)
            {
                //tell_object(find_player("redl"), sprintf("%s\n", ks[count-1]));
                switch (is_area(query("tele_users/" + ks[count - 1])) ) {
                case -1:
                case 0:
                    delete("tele_users/" + ks[count - 1]);
                    break;
                case 1:
                default :
                    ob = query("tele_users/" + ks[count - 1])["ob"];
                    if (ob && playerp(ob)) {
                        do_tell_back(ob);
                    }
                    break;
                }
            }
        }
        message_vision(append_color(NOR + CYN + "$N大聲宣佈：法陣開始維修，暫緩使用。\n" + NOR, CYN), me);
    }

    return 1;
}

int valid_leave(object me, string dir) {
    object room, *inv;
    int countp;
    int value, i = sizeof(sign);

    if (!interactive(me) || !playerp(me)) return 0;

    if (query("do_stop") && wiz_level(me) < 5 && dir != "southeast" && dir != "south" && dir != "southwest")
    {
        tell_object(me, NOR + "這裡正在維修，禁止使用！\n" + NOR);
        return -1;
    }

    if(me->query_condition("killer") ) {
        tell_object(me, NOR"你正在被通緝，無法進入飛星陣！\n"NOR);
        return -1;
    }

    inv = deep_inventory(me);
    if(sizeof(inv) > 0  && wiz_level(me) < 5 && dir != "southeast" && dir != "south" && dir != "southwest") {
        foreach(object ob2 in inv ) {
            if(ob2->is_character() && base_name(ob2)!="/clone/user/baby" ) {
                message_vision(append_color(NOR + CYN + "幾個機關人衝上來圍住$N，指了指他身上的$n。\n" + NOR, CYN), me, ob2);
                return -1;
            }
        }
    }

    if (query("exits/" + dir)) room = get_object(query("exits/" + dir));
    if (room && objectp(room) && query("max_carry_user", room)) { //限制人數
        inv = all_inventory(room);
        if(sizeof(inv) > 0 ) {
            foreach(object ob3 in inv ) {
                if (playerp(ob3) && wiz_level(ob3) < 5 ) countp ++;
            }
        }

        if(query("max_carry_user", room) < countp + 1 && wiz_level(me) < 5) {
            tell_object(me, "你發現對面的人太多了，出現空間不穩定的狀態，嚇得不敢踏進飛星陣。\n");
            me->start_busy(2);
            return -1;
        }
    }

    while(i--){
        if (sign[i]["exit"] && sign[i]["exit"]==dir) {
            value = sign[i]["val"];
            break;
        }
    }

    if (value && wiz_level(me) < 5){
        //if (wiz_level(me) < 5){
        if (query_temp("teleportroom/put_value", me) < value) {
            message_vision(append_color(NOR + CYN + "幾個機關人衝上來圍住$N，指了指石臺上的孔" + HIK + "(你的錢沒繳夠，look kong看清楚價格)" + NOR + CYN + "。\n" + NOR, CYN), me);
            me->start_busy(3);
            return -1;
        }
        else {
            addn_temp("teleportroom/put_value", -value, me);
            if (sign[i]["loop"]) {
                set("tele_users/" + query("id", me), ([ "ob": me,
                    "cost": value,
                    "path": sign[i]["loop"],
                    "time": time()
                    ]));
            }
            do_tell_val(me);
            message_vision(append_color(NOR + CYN + "$N" + (random(2) ? "輕輕" : "縱身") + "跳上" + (random(2) ? "石臺" : "法陣") + "，電閃雷鳴" + (random(2) ? "一聲霹靂響" : "一道極光裡") + "，$N的身影" + (random(2) ? "消失" : "遁去") + "。\n" + NOR, CYN), me);
            return 1;
        }
    }

    return ::valid_leave(me, dir);
}

void create() {
    set("short", HIG "飛星法陣" NOR);
    set ("long", NOR
        "這裡是一個特殊的陣法空間，八根巨大的石柱擎天而立，石柱中\n"
        "央漆黑一團，周圍閃爍著紫色白色黃色的電蛇。法陣外緣的石臺正中\n"
        "間有個小孔("CYN"kong"NOR")，邊上站著幾個傀儡機關人。\n"NOR
    );
    set("exits",([ /* sizeof() == 1 */
        "south": "/d/city/kedian4",
        "southeast": "/d/city/qiyuan/xxzl1",
        "southwest": "/u/redl/school/gate"
        ]));

    set("objects", ([
    //                                                "/u/redl/teleport/npc/tester" : 1
        ]));

    set("item_desc", ([
        "孔": (: look_kong :),
        "kong": (: look_kong :)
        ]) );
    set("no_dazuo", 1);
    set("no_kill", 1);
    set("no_fight", 1);
    set("no_steal", 1);
    set("no_beg", 1);
    set("no_rideto", 1);
    set("no_flyto", 1);
    set("no_magic", 1);
    set("no_sleep_room", 1);
    setup();
    create_exit();
    check_teleroom();
}
