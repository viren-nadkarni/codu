Public Class doctor

    Dim dbConn As New ADODB.Connection
    Dim recordCount As Integer
    Dim currentRecord As Integer

    Private Sub LogoutToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles LogoutToolStripMenuItem.Click
        Me.Close()
        login.Show()
    End Sub

    Private Sub doctor_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        dbConn.ConnectionString = "Driver={Microsoft ODBC for Oracle};" & "UID=System;PWD=sys"
        dbConn.Open()
    End Sub

    Private Sub ListBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ListBox1.SelectedIndexChanged

        Try
            Label5.Text = ""
            Label15.Text = "<date of last visit>"
            Label16.Text = "<treatment>"
            Label17.Text = "<diagnosis>"
            Label18.Text = "<complaints>"
            Label19.Text = "<index>"

            Dim recSet As New ADODB.Recordset

            If Not ListBox1.SelectedItem = "" And Not ListBox1.SelectedItem = "<no entries>" Then
                recSet.Open(("SELECT * FROM p_details WHERE name='" & ListBox1.SelectedItem & "'"), dbConn)

                Label6.Text = recSet.Fields(0).Value
                Label7.Text = recSet.Fields(1).Value
                Label11.Text = recSet.Fields(2).Value
                Label9.Text = recSet.Fields(3).Value

                recSet.Close()
                recSet.Open("SELECT * FROM p_health WHERE id=" & Label6.Text & " ORDER BY last_visit DESC", dbConn)

                recordCount = 0
                While recSet.EOF = False
                    recordCount = recordCount + 1
                    recSet.MoveNext()
                End While
                recSet.Close()

                recSet.Open("SELECT * FROM p_health WHERE id=" & Label6.Text & " ORDER BY last_visit DESC", dbConn)

                If recordCount > 0 Then
                    currentRecord = 1
                    Label19.Text = currentRecord & " of " & recordCount

                    recSet.Move(currentRecord - 1)

                    Label15.Text = recSet.Fields(1).Value
                    Label18.Text = recSet.Fields(2).Value
                    Label17.Text = recSet.Fields(3).Value
                    Label16.Text = recSet.Fields(4).Value
                End If

                TextBox1.Clear()
                TextBox2.Clear()
                TextBox3.Clear()

                recSet.Close()
            End If

        Catch ex As Exception

        End Try
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Try
            Dim recordCount As Integer
            Dim objRS As New ADODB.Recordset
            With objRS
                .CursorLocation = ADODB.CursorLocationEnum.adUseServer
                .CursorType = ADODB.CursorTypeEnum.adOpenForwardOnly
                .LockType = ADODB.LockTypeEnum.adLockReadOnly
            End With
            objRS.Open("SELECT count(*) FROM p_queue", dbConn)
            recordCount = objRS.Fields(0).Value
            objRS.Close()


            Dim sqlStr2 As String
            Dim recSet As New ADODB.Recordset
            Dim recSet2 As New ADODB.Recordset
            Dim counter As Integer
            counter = 0

            recSet.Open("SELECT id FROM p_queue ORDER BY place", dbConn)

            If recSet.EOF = False Then
                ListBox1.Items.Clear()

                Do While recSet.EOF = False And counter < recordCount

                    sqlStr2 = "SELECT name FROM p_details WHERE id=" & (recSet.Fields(0).Value)
                    recSet.MoveNext()

                    recSet2.Open(sqlStr2, dbConn)

                    ListBox1.Items.Add(Trim(recSet2.Fields(0).Value))

                    counter = counter + 1

                    recSet2.Close()
                Loop

            End If
            recSet.Close()

        Catch ex As Exception

        End Try
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        If Not Label6.Text = "<reg. no.>" Then
            saveChanges()
        Else
            Label5.Text = "No entry selected"
        End If
    End Sub

    Private Sub SaveChangesToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles SaveChangesToolStripMenuItem.Click
        saveChanges()
    End Sub

    Private Sub saveChanges()
        Try
            Dim sqlStr As String
            Dim recSet As New ADODB.Recordset

            If Not TextBox1.Text = "" And Not TextBox2.Text = "" And Not TextBox3.Text = "" Then
                sqlStr = "INSERT INTO p_health VALUES (" & Label6.Text & ",TO_DATE('" & DateTimePicker1.Value.Day _
                & "-" & DateTimePicker1.Value.Month & "-" & DateTimePicker1.Value.Year & "','DD-MM-YYYY'),'" & TextBox1.Text & "','" & TextBox2.Text _
                & "','" & TextBox3.Text & "')"

                Label5.Text = ""
                recSet.Open(sqlStr, dbConn)

                Label5.Text = "Changes were saved"

            Else
                Label5.Text = "All fields are required to be filled"

            End If

        Catch ex As Exception

        End Try
    End Sub

    Private Sub NextHistory_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles NextHistory.Click
        Try
            Dim recset As New ADODB.Recordset

            If (currentRecord < recordCount) Then
                recset.Open("SELECT * FROM p_health WHERE id=" & Label6.Text & " ORDER BY last_visit DESC", dbConn)
                currentRecord = currentRecord + 1
                recset.Move(currentRecord - 1)

                If recset.EOF = False Then
                    Label15.Text = recset.Fields(1).Value
                    Label18.Text = recset.Fields(2).Value
                    Label17.Text = recset.Fields(3).Value
                    Label16.Text = recset.Fields(4).Value
                    Label19.Text = currentRecord & " of " & recordCount

                End If
            End If

        Catch ex As Exception

        End Try
    End Sub

    Private Sub PrevHistory_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PrevHistory.Click
        Try
            Dim recset As New ADODB.Recordset

            If Not (currentRecord = 0) And Not currentRecord = 1 Then
                recset.Open("SELECT * FROM p_health WHERE id=" & Label6.Text & " ORDER BY last_visit DESC", dbConn)
                currentRecord = currentRecord - 1
                recset.Move(currentRecord - 1)

                If recset.EOF = False Then
                    Label15.Text = recset.Fields(1).Value
                    Label18.Text = recset.Fields(2).Value
                    Label17.Text = recset.Fields(3).Value
                    Label16.Text = recset.Fields(4).Value
                    Label19.Text = currentRecord & " of " & recordCount

                End If

            End If

        Catch ex As Exception

        End Try
    End Sub

End Class