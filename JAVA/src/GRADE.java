package LOOHCS;

import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class GRADE {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		JFrame myframe=new GFrame();
	      myframe.show();
	}

}

class GFrame extends JFrame implements ActionListener{
    private Connection con=null;
    private Statement stmt=null;
    private ResultSet  rs=null;
    private JLabel conditionlabel
        =new JLabel ("  ",SwingConstants.CENTER);
    private JLabel cnolabel=new JLabel("�γ̺�",SwingConstants.RIGHT);
    private JTextField cno=new JTextField(11);
    private JLabel snolabel=new JLabel("ѧ��",SwingConstants.RIGHT);
    private JTextField sno=new JTextField(11);
    private JLabel gradelabel=new JLabel("�ɼ�",SwingConstants.RIGHT);
    private JTextField grade=new JTextField(6);
    private JLabel titlelabel=new JLabel("        �γ̺�                 ѧ��                   �ɼ�",SwingConstants.RIGHT);
    private JButton commit=new JButton("��ѯ");
    private JButton insert=new JButton("����");
    private JButton change=new JButton("�޸�");
    private JLabel resultarea=new JLabel(" ",SwingConstants.RIGHT);
    private JTextArea resarea=new JTextArea(10,40); 
    private  String command=null;
    @SuppressWarnings("deprecation")
	public GFrame(){
        setTitle("�ɼ�����");
        setSize(500,350); 
        addWindowListener(new WindowAdapter(){
           public void windowClosing(WindowEvent e)
               { dispose(); }
        });
        getContentPane().setLayout(new GridBagLayout());
           //ʹ��GridBagLayout���ֱ���Swing���
        GridBagConstraints gbc=new GridBagConstraints();
        gbc.fill=GridBagConstraints.NONE;
        gbc.anchor=GridBagConstraints.CENTER; 
        gbc.weightx=100;
        gbc.weighty=100;
        add(conditionlabel,gbc,1,0,7,1);
        JScrollPane scrollpane=new JScrollPane(resarea);
        resarea.setEditable(false);
        resarea.setLineWrap(true);
        gbc.anchor=GridBagConstraints.EAST; 
        add(cnolabel,gbc,2,1,1,1); 
        add(snolabel,gbc,4,1,1,1); 
        add(gradelabel,gbc,6,1,1,1);
        gbc.anchor=GridBagConstraints.WEST;
        add(cno,gbc,3,1,1,1);
        add(sno,gbc,5,1,1,1);
        add(grade,gbc,7,1,1,1);
        add(titlelabel,gbc,2,3,4,1);
        gbc.anchor=GridBagConstraints.EAST; 
        add(commit,gbc,5,2,1,1);
        gbc.anchor=GridBagConstraints.CENTER; 
        add(insert,gbc,6,2,1,1);
        gbc.anchor=GridBagConstraints.WEST; 
        add(change,gbc,7,2,1,1); 
        gbc.anchor=GridBagConstraints.NORTH; 
        add(scrollpane,gbc,1,5,7,3);
        add(resultarea,gbc,2,2,4,3);
        commit.addActionListener(this);
        insert.addActionListener(this);
        change.addActionListener(this);
        commit.setNextFocusableComponent(cno); 
        try{
           Class.forName("com.mysql.jdbc.Driver");
           con=DriverManager.getConnection("jdbc:mysql://localhost:3306/school?autoReconnect=true&useUnicode=true&characterEncoding=UTF-8","root","1216");
           stmt=con.createStatement();
        } catch(Exception ex) {
           resultarea.setText(ex.getMessage()+"\n"); 
           return;
        }
      }
      public void add(Component c,GridBagConstraints gbc,int x,int y,
         int w, int h) {
         gbc.gridx=x;
         gbc.gridy=y;
         gbc.gridwidth=w;
         gbc.gridheight=h;
         getContentPane().add(c,gbc);
      }
      public void actionPerformed(ActionEvent evt) {
    	 String cnovalue=cno.getText().trim();
    	 String snovalue=sno.getText().trim();
    	 String gradevalue=grade.getText().trim();
    	 if(evt.getSource()==commit){
    		 if(!snovalue.equals("")&!cnovalue.equals("")){
    		 command="SELECT grade FROM sc WHERE cno="+cnovalue+" AND sno="+snovalue;
    		 try{
                 rs=stmt.executeQuery(command);
                 if(rs.next()) 
                 { 
                       resultarea.setText("��ѯ�ɹ�");
                       String regrade=rs.getString("grade").trim();
                       grade.setText(regrade);
                 } 
                   else{
                	   grade.setText("");
                	   resultarea.setText("�޴˼�¼");
                   } 
               }
            catch(Exception ex) {
               resultarea.setText(ex.getMessage());
           }
    		 }
    		 else resultarea.setText("������Ҫ��ѯ�ɼ��Ŀγ̺ź�ѧ��");
    	 }
    	 else if(evt.getSource()==insert){
    		 if(!snovalue.equals("")&!cnovalue.equals("")&!gradevalue.equals("")){
    		 command="SELECT * FROM course WHERE cno="+cnovalue;
    		 try{
                 rs=stmt.executeQuery(command);
                 if(rs.next()) 
                 { 
                	 command="SELECT * FROM student WHERE sno="+snovalue;
                	 try{
                         rs=stmt.executeQuery(command);
                         if(rs.next()) 
                         {   command="SELECT grade FROM sc WHERE cno="+cnovalue+" AND sno="+snovalue;
                		 try{
                             rs=stmt.executeQuery(command);
                             if(rs.next()) 
                             {  
                                   resultarea.setText("�ظ�����ѡ���Ƿ����");
                                   String regrade=rs.getString("grade").trim();
                                   grade.setText(regrade);
                             } 
                               else{
                            	   command="insert into sc values("+cnovalue+","+snovalue+","+gradevalue+")"; 
                          		 try{
                                 	     stmt.executeUpdate(command);
                                       resultarea.setText("�ɹ�����һ���ɼ���¼");
                                     }
                                   catch(Exception ex) {
                                     resultarea.setText(ex.getMessage());
                                    }
                               } 
                           }
                        catch(Exception ex) {
                           resultarea.setText(ex.getMessage());
                       }
                        	 
                         } 
                           else{
                        	   grade.setText("");
                        	   resultarea.setText("��������ȷ��ѧ��");
                           } 
                       }catch(Exception ex) {
                           resultarea.setText(ex.getMessage());
                       }
                 } 
                   else{
                	   grade.setText("");
                	   resultarea.setText("��������ȷ�Ŀγ̺�");
                   } 
               }
            catch(Exception ex) {
               resultarea.setText(ex.getMessage());
           }
    	 }
		 else resultarea.setText("������Ҫ����ɼ�����Ϣ");
    	 }
    	 else if(evt.getSource()==change){
    		 if(!snovalue.equals("")&!cnovalue.equals("")&!gradevalue.equals("")){
    		 command="update sc set grade='"+gradevalue+ "' where cno="+cnovalue+" and sno="+snovalue;
    		 try{
           	     stmt.executeUpdate(command);
                 resultarea.setText("�ɹ�����һ���ɼ���¼");
               }
             catch(Exception ex) {
               resultarea.setText(ex.getMessage()+"\n"+command+"\n");
              }
    		 }
    		 else resultarea.setText("������Ҫ���³ɼ�����Ϣ");
    	 }
    	 try{
             command="SELECT * FROM sc ORDER BY cno DESC"; 
             rs=stmt.executeQuery(command);
             resarea.setText("");
             if(rs.next()) 
             { 
               do{
                   String recno=rs.getString("cno").trim();
                   String resno=rs.getString("sno").trim();
                   String regrade=rs.getString("grade").trim();
                   resarea.append(recno);//����
                   resarea.append("\t");
                   resarea.append(resno);//����
                   resarea.append("\t");
                   resarea.append(regrade+"              \n"); 
               }while(rs.next());
           }
       } catch(Exception ex) {
           resarea.append(ex.getMessage()+"\n"+command+"\n");
       }  
     
    }
}