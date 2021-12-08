package com.jadru;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.HashMap;
import java.util.Vector;

import static com.jadru.Prac_7_8.students;

public class Prac_7_8 extends JFrame {
    static HashMap<String, Integer> students;
    static JPanel container;
    static JTable table;
    static DefaultTableModel tb;

    Prac_7_8(){
        container = new JPanel(); // JPanel 생성
        setContentPane(container);
        setTitle("자바 과제 6번");
        setSize(600, 800);
        setLayout(null);

        Dimension frameSize = getSize();
        Dimension windowSize = Toolkit.getDefaultToolkit().getScreenSize();
        setLocation((windowSize.width - frameSize.width) / 2, // 화면 중앙
                (windowSize.height - frameSize.height) / 2);

        students = new HashMap<>(); // 해쉬맵 생성
        JLabel label = new JLabel("포인트 관리 프로그램입니다");
        JButton button = new JButton("추가");
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new MyDialog(Prac_7_8.this); // 다이얼로그 호출
            }
        });
        tb = new DefaultTableModel(0, 2); // 디폴트테이블모델 호출
        table = new JTable(tb); // 테이블에 추가

        label.setBounds(200, 0, 500, 100);
        button.setBounds(350, 25, 50, 50);
        table.setBounds(100, 150, 400, 550);

        fillTable(); // 테이블 그리는 함수

        add(label);
        add(button);
        add(table);

        setVisible(true);
    }

    public static void fillTable()
    {
        table.removeAll(); // 테이블 전부 삭제
        if (tb.getRowCount() > 0) { // 테이블 모델에 남는 row가 있다면
            for (int i = tb.getRowCount() - 1; i > -1; i--) {
                tb.removeRow(i); // 전부 삭제
            }
        }
        for(HashMap.Entry<String, Integer> data : students.entrySet()) // 해시맵에 항목이 있으면
        {
            Vector<Object> row = new Vector<>(2); // 벡터 생성
            row.addElement(data.getKey()); // 이름 추가
            row.addElement(data.getValue()); // 포인트 추가
            System.out.println(row);
            tb.addRow(row); // 테이블 모델에 벡터 추가
        }
        table.updateUI(); // 테이블 업데이트
    }

    public static void main(String[] args) {new Prac_7_8();}
}

class MyDialog extends JDialog {

    public MyDialog(JFrame frame) {
        super(frame, "추가하기", true);
        setLayout(new GridLayout(3, 1));
        setSize(300, 200);
        Dimension frameSize = getSize();
        Dimension windowSize = Toolkit.getDefaultToolkit().getScreenSize();
        setLocation((windowSize.width - frameSize.width) / 2, // 화면 중앙
                (windowSize.height - frameSize.height) / 2);

        JTextField tf1 = new JTextField();
        JTextField tf2 = new JTextField();
        JButton button = new JButton("추가");

        add(tf1);
        add(tf2);
        add(button);

        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                boolean isexist = false;
                for (HashMap.Entry<String, Integer> data : students.entrySet()) {
                    if (data.getKey().equals(tf1.getText())) { // 만약 해시맵에 key와 같으면
                        data.setValue(data.getValue() + Integer.parseInt(tf2.getText())); // value만 추가
                        isexist = true;
                    }
                }
                    if(!isexist) // 해시맵에 없다면
                        students.put(tf1.getText(), Integer.parseInt(tf2.getText())); // key와 value를 추가
                Prac_7_8.fillTable(); // 테이블 다시 그리기
                repaint();
                revalidate();
                dispose(); // 다이얼로그 삭제
            }
        });
        setVisible(true);
    }
}
