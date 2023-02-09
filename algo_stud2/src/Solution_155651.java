import java.util.*;

class Room implements Comparable<Room> {
  private int begin;
  private int end;

  Room(String[] book_time) {
    setTime(book_time);
  }

  int calcTime(String time) {
    String[] split = time.split(":");
    int hour = Integer.parseInt(split[0]) * 60;
    int min = Integer.parseInt(split[1]);

    return hour + min;
  }

  void setTime(String[] book_time) {
    begin = calcTime(book_time[0]);
    end = calcTime(book_time[1]) + 10;
  }

  void setBeginTime(int new_begin) {
    begin = new_begin;
  }

  void setEndTime(int new_end) {
    end = new_end;
  }

  int getBeginTime() {
    return begin;
  }

  int getEndTime() {
    return end;
  }

  @Override
  public int compareTo(Room o) {
    if (end < o.end)
      return -1;
    else if (end > o.end)
      return 1;
    else
      return 0;
  }
}

public class Solution_155651 {

  public static int solution(String[][] book_time) {
    List<Room> room = new ArrayList<>();

    // 계산의 편의를 위해서 string type의 book_time을 모두 Room 객체로 변환
    Room[] rooms = new Room[book_time.length];
    for (int i = 0; i < rooms.length; i++) {
      rooms[i] = new Room(book_time[i]);
    }

    Comparator<Room> cp = new Comparator<>() {
      @Override
      public int compare(Room n1, Room n2) {
        return n1.getBeginTime() - n2.getBeginTime();
      }
    };
    Arrays.sort(rooms, cp);

//    for (Room r : rooms) {
//      System.out.println(r.getBeginTime());
//
//    }

    room.add(rooms[0]);
    for (int i = 1; i < rooms.length; i++) {
      Collections.sort(room);
      for (int j = 0; j < room.size(); j++) {
        if (room.get(j).getEndTime() <= rooms[i].getBeginTime()) {
          room.get(j).setEndTime(rooms[i].getEndTime());
          break;
        } else if (rooms[i].getEndTime() <= room.get(j).getBeginTime()) {
          room.get(j).setBeginTime(rooms[i].getBeginTime());
          break;
        } else {
          if (j == room.size() - 1) {
            room.add(rooms[i]);
            break;
          }
        }
      }
    }

    int answer = room.size();
    return answer;
  }

  public static void main(String[] args) {
    String[][] book_time = {{"15:00", "17:00"}, {"16:40", "18:20"}, {"14:20", "15:20"}, {"14:10", "19:20"}, {"18:20", "21:20"}};

    System.out.println(solution(book_time));
  }
}
