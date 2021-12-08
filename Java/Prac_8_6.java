package com.jadru;

import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;

public class Prac_8_6 extends JFrame {
    static JPanel container;
    JLabel label4;

    Prac_8_6(){
        container = new JPanel(); // JPanel 생성
        setContentPane(container);
        setTitle("자바 과제 6번");
        setSize(600, 600);
        setLayout(null);

        Dimension frameSize = getSize();
        Dimension windowSize = Toolkit.getDefaultToolkit().getScreenSize();
        setLocation((windowSize.width - frameSize.width) / 2, // 화면 중앙
                (windowSize.height - frameSize.height) / 2);

        JLabel title = new JLabel("텍스트 파일 이어붙이기"); // GUI 생성
        JLabel label1 = new JLabel();
        JLabel label2 = new JLabel();
        JLabel label3 = new JLabel();
        label4 = new JLabel();
        JButton btn1 = new JButton("텍스트 파일1 선택");
        JButton btn2 = new JButton("텍스트 파일2 선택");
        JButton btn3 = new JButton("파일 저장 경로 선택");
        JButton run = new JButton("파일 합치기 실행");

        title.setBounds(100, 0, 400, 100);
        btn1.setBounds(100, 100, 200, 100);
        btn2.setBounds(100, 200, 200, 100);
        btn3.setBounds(100, 300, 200, 100);
        run.setBounds(100, 400, 200, 100);
        label1.setBounds(300, 100, 200, 100);
        label2.setBounds(300, 200, 200, 100);
        label3.setBounds(300, 300, 200, 100);
        label4.setBounds(300, 400, 200, 100);


        add(title); add(label1); add(btn1);
        add(label2); add(btn2);  add(label3); add(btn3);
        add(label4); add(run);

        setVisible(true);

        btn1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFileChooser chooser = new JFileChooser(); // 파일 선택기 실행
                chooser.setFileFilter(new FileNameExtensionFilter("TXT", "txt")); // 텍스트 파일로 한정
                int ret = chooser.showOpenDialog(null); // 다이얼로그 실행
                if (ret == JFileChooser.APPROVE_OPTION){ // 확인을 누르면
                    String path = chooser.getSelectedFile().getPath(); // 경로 불러오기
                    label1.setText(path);
                }
            }
        });

        btn2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFileChooser chooser = new JFileChooser();
                chooser.setFileFilter(new FileNameExtensionFilter("TXT", "txt"));
                int ret = chooser.showOpenDialog(null);
                if (ret == JFileChooser.APPROVE_OPTION){
                    String path = chooser.getSelectedFile().getPath();
                    label2.setText(path);
                }
            }
        });

        btn3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFileChooser chooser = new JFileChooser();
                chooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY); // 폴더만 선택 가능하게
                int ret = chooser.showOpenDialog(null);
                if (ret == JFileChooser.APPROVE_OPTION){
                    String path = chooser.getSelectedFile().getPath(); // 폴더 경로 불러오기
                    label3.setText(path);
                }
            }
        });

        run.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                mergeFile(label1.getText(), label2.getText(), label3.getText()); // 3개를 merge
            }
        });
    }

    public void mergeFile(String file1path, String file2path, String savedirectory){
        try{
            BufferedReader br1 = new BufferedReader(new FileReader(file1path)); // 파일의 buffered reader 생성
            BufferedReader br2 = new BufferedReader(new FileReader(file2path));
            BufferedWriter bw = new BufferedWriter(new FileWriter(savedirectory+"/new.txt")); // new 파일 writer 생성

            String c;

            while((c=br1.readLine())!=null) { // 라인별로
                bw.write(c); // 추가 후
                bw.write("\n"); // 엔터
            }
            while((c=br2.readLine())!=null) {
                bw.write(c);
                bw.write("\n");
            }
            bw.flush(); // 플러시
            label4.setText("run.txt로 저장 완료!"); // 완료 안내
        }catch(Exception e){
            System.out.println(e.getMessage());
        }

    }

    public static void main(String[] args) {new Prac_8_6();}
}
