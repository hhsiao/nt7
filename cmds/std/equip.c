#include <ansi.h>

inherit F_CLEAN_UP;
#include <equip.h>
#include <equipment.h>

int main(object me, string arg) {
    int status;
    object ob, *obs;
    int equip_from_environment;
    int num;

    if(!arg )
    {
        string msg;
        object *equipments = me->query_equipment_objects();

        if(!sizeof(equipments) )
            return tell(me, pnoun(2, me) + "目前身上沒有任何裝備。\n");

        msg = pnoun(2, me) + "目前身上的裝備如下：\n";

        foreach(ob in me->query_equipment_objects())
        //msg += "．"HIW"["NOR+me->query_equipping_part(ob)+HIW"] "+ob->query_idname()+"\n"NOR;
        msg += "．"HIW"["NOR + me->query_equipping_part(ob) + HIW"] "+ob->query_idname() + "\n"NOR;

        tell(me, msg + "\n");
        return 1;
    }

    //忙碌中不能下指令
    if(me->is_busy() )
    {
        tell(me, BUSY_MESSAGE);
        me->show_prompt();
        return 1;
    }

    if(sscanf(arg, "-s %d", num) == 1 )
    {
        if(num < 1 || num > 5 )
            return tell(me, "最多隻能設定 5 組套裝。\n");

        set("equipment_set/"+num, map(me->query_equipment_objects(), (: base_name($1) :)), me);
        me->save();

        tell(me, pnoun(2, me) + "將目前的裝備設定為第 "+num + " 號套裝。\n");
        return 1;
    }
    else if(sscanf(arg, "-d %d", num) == 1 )
    {
        if(!query("equipment_set/"+num, me) )
            return notify_fail(pnoun(2, me) + "原本並沒有設定第 "+num + " 號套裝。\n");

        delete("equipment_set/"+num, me);
        me->save();

        tell(me, pnoun(2, me) + "將第 "+num + " 號套裝設定刪除。\n");
        return 1;
    }
    else if(sscanf(arg, "-l %d", num) == 1 )
    {
        string msg;
        string *equipment_set = query("equipment_set/"+num, me);

        if(!arrayp(equipment_set) )
            return notify_fail(pnoun(2, me) + "原本並沒有設定第 "+num + " 號套裝。\n");

        msg = pnoun(2, me) + "所設定的 "+num + " 號套裝如下：\n";

        foreach(string basename in equipment_set)
        {
            ob = load_object(basename);
            if(!objectp(ob) ) continue;
            msg += "．"HIW"["NOR + me->query_equipping_part(ob) + HIW"] "+ob->query_idname() + "\n"NOR;
        }

        tell(me, msg);
        return 1;
    }
    else if(sscanf(arg, "%d", num) == 1 )
    {
        int index;
        string *equipment_set = query("equipment_set/"+num, me);

        if(time() - query_temp("last_equip", me) < 10 )
            return notify_fail("系統氣喘噓地嘆道：請稍後再使用equip換裝。\n");

        if(!arrayp(equipment_set) )
            return notify_fail(pnoun(2, me) + "並沒有設定第 "+num + " 號套裝。\n");

        obs = all_inventory(me);
        obs = filter_array(obs, (: $1->is_equipment() :));

        /*
         * foreach(ob in obs)
         * {
         * if( me->is_equipping_object(ob) )
         * {
         * me->unequip(ob, ref status);

         * //      msg("$ME卸除了裝備在「"+me->query_equipping_part(ob)+"」部位上的"+ob->query_idname()+"。\n", me, 0, 1);
         * }
         * }
         */
        me->unequip_all();
        foreach(ob in obs)
        {
            //reset_eval_cost();
            index = member_array(base_name(ob), equipment_set);

            if(index == -1 ) continue;

            equipment_set = equipment_set[0..index - 1] + equipment_set[index + 1..];

            if(me->equip(ob, ref status) )
                msg("$ME將"+ob->query_idname() + "裝備在「"+me->query_equipping_part(ob) + "」的部位上。\n", me, 0, 1);
            else
            {
                switch(status)
                {
                    // 1: 此物件不是裝備
                    // 2: 無法裝備在此物件上
                    // 3: 不知此物件該裝備在何處
                    // 4: 已經有同種類的裝備
                    // 5: 已經裝備在其他的部位上

                case 1: tell(me, ob->query_idname() + "無法用來裝備。\n"); break;
                case 2: tell(me, pnoun(2, me) + "似乎沒有足夠的能力來裝備這個物品。\n"); break;
                case 3: tell(me, pnoun(2, me) + "不瞭解"+ob->query_idname() + "該裝備在何處。\n"); break;
                case 4: tell(me, pnoun(2, me) + "身上該部位上已經裝備著其他物品。\n"); break;
                case 5: tell(me, ob->query_idname() + "已經裝備在其他的部位上了。\n"); break;
                default: error("裝備物品發生錯誤。\n"); break;
                }
            }
        }
        set_temp("last_equip", time(), me);

        return 1;
    }

    if(arg == "all" )
    {
        foreach(ob in all_inventory(me))
        {
            if(!ob->is_equipment() ) continue;
            if(query_temp("no_wear", ob) ) continue;
            if(me->is_equipping_object(ob) )
                tell(me, pnoun(2, me) + "已經將"+ob->query_idname() + "裝備在「"+me->query_equipping_part(ob) + "」的部位上了。\n");
            if(me->equip(ob, ref status) )
                msg("$ME將"+ob->query_idname() + "裝備在「"+me->query_equipping_part(ob) + "」的部位上。\n", me, 0, 1);
        }

        return 1;
    }

    if(!objectp(ob = present(arg, me)) )
    {
        if(objectp(ob = present(arg, environment(me))) && !ob->is_living() )
        {
            equip_from_environment = 1;
        }
        else
            return notify_fail("這附近並沒有 "+arg + " 這個物品。\n");
    }

    if(query_temp("no_wear", ob) )
    {
        return notify_fail("還是試試別的吧！\n");
    }

    if(me->is_equipping_object(ob) )
        return notify_fail(pnoun(2, me) + "已經將"+ob->query_idname() + "裝備在「"+me->query_equipping_part(ob) + "」的部位上了。\n");

    if(!me->equip(ob, ref status) )
    {
        switch(status)
        {
            // 1: 此物件不是裝備
            // 2: 無法裝備在此物件上
            // 3: 不知此物件該裝備在何處
            // 4: 已經有同種類的裝備
            // 5: 已經裝備在其他的部位上

        case 1: return notify_fail(ob->query_idname() + "無法用來裝備。\n"); break;
        case 2: return notify_fail(pnoun(2, me) + "似乎沒有足夠的能力來裝備這個物品。\n"); break;
        case 3: return notify_fail(pnoun(2, me) + "不瞭解"+ob->query_idname() + "該裝備在何處。\n"); break;
        case 4: return notify_fail(pnoun(2, me) + "身上該部位已經裝備著其他物品。\n"); break;
        case 5: return notify_fail(ob->query_idname() + "已經裝備在其他的部位上了。\n"); break;
        default: error("裝備物品發生錯誤。\n"); break;
        }
    }
    else
    {
        msg("$ME將"+ob->query_idname() + "裝備在「"+me->query_equipping_part(ob) + "」的部位上。\n", me, 0, 1);

        if(equip_from_environment )
            ob->move(me, 1);
    }
    return 1;
}

int help(object me) {
    string help = @HELP
    裝備物品的指令，無論是武器、防具、裝飾品、團體武裝都
是利用此指令進行裝備動作。

equip '物品'            - 裝備某項物品
equip -s 2              - 將目前身上裝備之所有物品設定為 2 號套裝
equip -d 2              - 刪除 2 號套裝設定
equip -l 2              - 查詢 2 號套裝設定
equip 2                 - 將身上裝備換裝為 2 號套裝
HELP;
    write(help);
    return 1;
}
