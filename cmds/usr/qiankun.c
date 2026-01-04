// qiankun.c
// redl 2015/10

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);

int do_beep(object obj) {
    if (! obj) return 1;
    tell_object(obj, "\a", 0);
    return 1;
}

void bp(object obj) {
    call_out("do_beep", 1, obj);
    call_out("do_beep", 2, obj);
    call_out("do_beep", 3, obj);
    call_out("do_beep", 4, obj);
}

int main(object me, string arg) {
    object room, qkroom;
    string roompath;
    string ownid, myid;
    string* guests;
    object guest;
    string file;
    string str;
    object *obs, cha;
    int r_type = 0;

    if (!arg ) return help(me);
    room = environment(me);
    if (!room) return 0;
    roompath = base_name(room);
    if(sscanf(roompath, "/d/register/%*s") ) return notify_fail("你還沒有出生呢，不能施展！\n");
    if(sscanf(roompath, "/d/newbie/%*s") ) return notify_fail("你在古村中，不能施展！\n");
    if (me->is_ghost()) return notify_fail("等你還了陽再說吧。\n");
    if (me->is_in_prison()) return notify_fail("你正在做牢呢。\n");
    if(query("doing", me) ) return notify_fail("你還想幹什麼？！\n");

    //召喚茶寵功能
    if (arg == "alarm" || arg == "help") {
        if (room->is_qkroom()) return notify_fail("你在乾坤棋盤裡無法使用這個功能。\n");
        if (query("qkhelpkill_time", me) >= time()) return notify_fail("你正在召喚茶寵中。\n");
        myid = query("id", me);
        file = "/temp/qroom/" + myid + ".c";
        qkroom = get_object(file);
        if (!qkroom) return notify_fail("你尚未進入過乾坤棋盤。\n");
        obs = all_inventory(qkroom);
        foreach (cha in obs) {
            if (query("id", cha) == "cha chong") {
                cha->do_helpkill(me, cha);
                r_type = 1;
                break;
            }
        }
        set("qkhelpkill_time", time() + 1, me);
        me->start_busy(2);
        if (!r_type) write("你的棋盤裡目前沒有待命的茶寵。\n");
        return 1;
    }

    if (me->is_busy()) return notify_fail("你正忙著呢。\n");
    me->start_busy(1);

    //空間變幻功能
    if (present("biao huo", me)) return notify_fail("你身上帶著鏢銀，不能施展！\n");
    if (me->is_fighting()) return notify_fail("你現在正在戰鬥！\n");
    if(query_temp("warquest/party", me) ) return notify_fail("你還想在戰爭中使用？！\n");
    if(query("no_magic", room) || query_temp("in_pkd", me) ) return notify_fail("你發現這裡不可以施展！\n");
    if (sscanf(roompath, "%*s/dongtian/%*s")) return notify_fail("洞天隔絕了空間！\n");
    if (sscanf(roompath, "%*s/teleport/%*s")) return notify_fail("福地隔絕了空間！\n");
    if (sscanf(roompath, "/f/%*s")) return notify_fail("你發現這裡不可以施展！\n");

    if (sscanf(arg, "%s %s", arg, str) == 2) {
        if (!room->is_qkroom()) return notify_fail("你現在沒有身處乾坤棋盤內，無法使用這個功能。\n");
        if (!sscanf(roompath, "%*s/qroom/%s", ownid)) return help(me);
        if (query("id", me) != ownid) return notify_fail("這個棋盤裡你做不了主。\n");
        if (arg == "add") {
            guests = query("guests", room);
            if (!guests || !sizeof(guests)) guests = ({});
            if (sizeof(guests) >= query("qiankunqipan/limit_guest", me)) return notify_fail("你的乾坤白棋子數量不足。\n");
            if (member_array(str, guests)<0) {
                guests += ({ str });
                set("guests", guests, room);
            }
            message_vision(NOR YEL "$N" NOR YEL  "捻起一枚白棋落在棋盤上，棋子上慢慢閃現一個深痕\"" + str + "\"。\n" NOR, me);
            //                              guest = find_player(str);
            //                              if (guest && objectp(guest)) {
            //                                      tell_object(guest, NOR HIG "你識海里傳來一陣波動，原來是" + me->name() + NOR HIG "邀請你進入乾坤棋盤。" NOR HIK " ( 在合適的位置輸入：qiankun " + ownid + " )\n" NOR);
            //                                      bp(guest);
            //                              }
            return 1;
        }
        else if (arg == "clear") {
            guests = query("guests", room);
            if (!guests || !sizeof(guests)) guests = ({});
            guest = find_player(str);
            if (guest && objectp(guest) && environment(guest)==room) { //驅逐
                message_vision(NOR YEL "$N" NOR YEL  "伸出手指一點，一枚棋子把"NOR YEL "$n" NOR YEL "壓落到了虛空。\n" NOR, me, guest);
                if (query("startroom", guest)==roompath) delete("startroom", guest);
                guest->move(VOID_OB);
                guest->save();
                if(query("doing", guest) ) "/cmds/usr/scheme.c"->cancel_schedule(guest);
            }
            if (member_array(str, guests)<0 && query("guesttmp", room)!=str) {
                write("你沒有邀請過這個人。\n");
                return 1;
            }
            guests -= ({ str });
            set("guests", guests, room);
            if (query("guesttmp", room)==str) delete("guesttmp", room);
            message_vision(NOR YEL "$N" NOR YEL  "捻起一枚寫著\"" + str + "\"的白棋子收回懷裡。\n" NOR, me);
            if (query("guesttmp", room) && member_array(query("guesttmp", room), guests)<0) guests += ({ query("guesttmp", room) });
            if (sizeof(guests))
                tell_object(me, NOR "你目前邀請的客人有："+implode(guests, ",") + "。\n" NOR);
            else
                tell_object(me, NOR "你目前沒有邀請任何客人。\n" NOR);
            return 1;
        }
        return help(me);
    } else {
        if (arg == "here") {
            if (query("qiankunqipan/limit_guest", me) < 4) return notify_fail("你的乾坤黑棋子數量不足。\n");
            if (sscanf(roompath, "/d/%*s")) r_type = 1;
            if (sscanf(roompath, "/data/room/%*s")) r_type = 2;
            if (room->is_qkroom()) return notify_fail("你想在乾坤棋盤裡嵌套乾坤棋盤？腦洞真大...\n");
            if (!query("no_fight", room)) return notify_fail("你不能在非安全房間放置黑棋。\n");
            if (query("valid_startroom", room)) r_type = 0;
            if (room->is_chat_room()) r_type = 0;
            if (!r_type) return notify_fail("你不能在這裡放置黑棋。\n");
            file = "/temp/qroom/" + query("id", me) + ".c";
            if (file_size(file) < 1) return notify_fail("你尚未進入過乾坤棋盤。\n");
            qkroom = get_object(file);
            if (!qkroom) return notify_fail("你的乾坤棋盤錯誤。\n");
            set("to_down", roompath, qkroom);
            message_vision(NOR YEL "$N" NOR YEL  "拋出枚本命黑棋子扔在地上，棋子慢慢地侵入了土中，逐漸消失不見。\n" NOR, me);
            tell_object(me, NOR "你可以從自己的乾坤棋盤內直接降臨這裡了。\n" NOR);
            return 1;
        }
        else if (arg == "clear") {
            if (!room->is_qkroom()) return notify_fail("你現在沒有身處乾坤棋盤內，無法使用這個功能。\n");
            if (!sscanf(roompath, "%*s/qroom/%s", ownid)) return help(me);
            if (query("id", me) != ownid) return notify_fail("這個棋盤裡你做不了主。\n");
            obs = all_inventory(room);
            foreach (object ep in obs) { //驅逐
                //write(ep->name() + "\n");
                if (!playerp(ep)) continue;
                if (ep == me) continue;
                message_vision(NOR YEL "$N" NOR YEL  "伸出手指一點，一枚棋子把"NOR YEL "$n" NOR YEL "壓落到了虛空。\n" NOR, me, ep);
                if (query("startroom", ep)==roompath) delete("startroom", ep);
                ep->move(VOID_OB);
                ep->save();
                if(query("doing", ep) ) "/cmds/usr/scheme.c"->cancel_schedule(ep);
            }
            delete("guests", room);
            delete("guesttmp", room);
            message_vision(NOR YEL "$N" NOR YEL  "把棋盤上所有的白棋子收回懷裡。\n" NOR, me);
            tell_object(me, NOR "你目前沒有邀請任何客人。\n" NOR);
            return 1;
        }
        else {
            if (room->is_qkroom()) {
                if (!sscanf(roompath, "%*s/qroom/%s", ownid)) return help(me);
                if (query("id", me) != ownid) return notify_fail("這個棋盤裡你做不了主。\n");
                if (query("id", me) == arg) return notify_fail("你到外面再直接使用這指令吧。\n");
                guest = find_player(arg);
                if (guest && objectp(guest)) {
                    if (environment(guest)==room) return notify_fail("這人現在不就在眼前麼？\n");
                    tell_object(guest, NOR HIG "你識海里傳來一陣波動，原來是" + me->name() + NOR HIG "邀請你進入乾坤棋盤。" NOR HIK " ( 在合適的位置輸入：qiankun " + ownid + " )\n" NOR);
                    bp(guest);
                }
                set("guesttmp", arg, room);
                message_vision(NOR YEL "$N" NOR YEL  "捻起一枚白棋落在棋盤上，棋子上慢慢閃現一個淡影\"" + arg + "\"。\n" NOR, me);
                tell_object(me, NOR "你臨時邀請了\"" + arg + "\"進入這裡。\n" NOR);
                return 1;
            } else {
                file = "/temp/qroom/" + arg + ".c";
                //if (file_size(file) < 1) return notify_fail("對方尚未進入過乾坤棋盤。\n");
                qkroom = get_object(file);
                if (!qkroom) return notify_fail("對方尚未進入過乾坤棋盤。\n");
                guests = query("guests", qkroom);
                if (!guests || !sizeof(guests)) guests = ({});
                if (member_array(query("id", me), guests)<0 && query("guesttmp", qkroom)!=query("id", me) && arg!=query("id", me)) return notify_fail("對方未邀請你進入乾坤棋盤。\n");
                if (query("guesttmp", qkroom)==query("id", me)) delete("guesttmp", qkroom);
                message_vision(NOR YEL "一片青霞飛來，轉眼變成白洞漩渦，把" NOR YEL "$N" NOR YEL  "吞下消失了。\n" NOR, me);
                me->move(qkroom);
                message_vision(NOR YEL "天上青霞舒捲，現出道空間漩渦，一張一吐，" NOR YEL "$N" NOR YEL  "從裡面滾落出來。\n" NOR, me);
                return 1;
            }
        }
    }

    return help(me);
    return 1;
}

int help(object me) {
    write(@HELP
 《乾坤棋盤大召喚》
指令格式 : qk|qiankun
  主人在乾坤棋盤裡邀請人的指令為 < qk sb > ，sb是臨時客人id，同時最多一位。
  主人在乾坤棋盤裡邀請人的指令為 < qk add sb > ，sb是客人id，能一直保持邀請。
  主人在乾坤棋盤裡清除白棋指令為 < qk clear sb> ，取消對某客人的邀請，不帶sb參數則全部取消。
  主人在棋盤外設置黑棋位置指令為 < qk here > ，黑棋只有1顆，只能設置在尋常的安全房間內。
  客人在棋盤外呼應被召喚的指令為 < qk sb > ，sb是主人id。
  主人在棋盤外召喚茶寵護法指令為 < qk help > ，參數help或者alarm需要先利用乾坤符昭收伏敵人為茶寵。
由於乾坤召喚可能導致很多任務流程的改變，必須算是道家的珍稀秘術。
一次性購入的代價不菲，參見ntstore look qiankunqi。
HELP
    );
    return 1;
}
